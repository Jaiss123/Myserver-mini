#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include "Tcpserver.h"

using namespace std;

int tcpserver::CreateAndListen(char * a){
	int on = 1;
	int serverfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	//将serverfd设置成非阻塞IO
	fcntl(serverfd,F_SETFL,O_NONBLOCK);
	memset(&servaddr, 0, sizeof(servaddr));
	setsockopt(serverfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(a));

	if(-1 == bind(serverfd,(struct sockaddr*)&servaddr,sizeof(servaddr)))
		cout << "bind error, errno: "<<errno<<endl;
	if(-1 == listen(serverfd,MAX_LISTENFD))
		cout << "listen error,errno:" << errno <<endl;

	return serverfd;	

}


void tcpserver::start(){
	struct epoll_event ev, events[MAX_EVENTS];
	int serverfd,clienfd,sockfd;
	int readlength;
	char line[MAX_LINE];
	struct sockaddr_in cliaddr;

	socklen_t clilen = sizeof(struct sockaddr_in);
	int epoll_fd = epoll_create(MAX_EVENTS);
	if(epoll_fd < 0)
		cout << "epoll_create error,error:"<< epoll_fd <<endl;

	serverfd = CreateAndListen(port);
	ev.data.fd = serverfd;
	ev.events = EPOLLIN;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, serverfd, &ev);

	while(1){

		int num_fds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
		
		/*打印操作符****************************/
		cout <<"监听到的描述符有： ";
		for (int i = 0; i < num_fds; ++i)
		{
			cout << events[i].data.fd << " ";
		}
		cout << endl;
		/*************************************/

		if(num_fds == -1){
			cout << "epoll_wait error: errno" << errno << endl;
			break;
		}

		for(int i = 0; i < num_fds; i++ )
		{
			if(events[i].data.fd == serverfd){
				clienfd = accept(serverfd, (sockaddr*)&cliaddr, (socklen_t*)&clilen);
				if(clienfd > 0 ){
					cout << "new connection from " 
                         << "[" << inet_ntoa(cliaddr.sin_addr) 
                         << ":" << ntohs(cliaddr.sin_port) << "]" 
                         << " accept socket fd:" << clienfd 
                         << endl;
				}
				else{
					cout << "accept error, clienfd:" << clienfd 
                         << " errno:" << errno << endl; 
                         continue;
				}

				//将新的socket加入到epoll的监听范围
				fcntl(clienfd, F_SETFL, O_NONBLOCK);
				ev.data.fd = clienfd;
				ev.events = EPOLLIN;
	            if( -1 == epoll_ctl(epoll_fd, EPOLL_CTL_ADD, clienfd, &ev))
                    cout << "epoll_ctrl error, errno:" << errno << endl;
			}
			else if(events[i].events & EPOLLIN){
				if((sockfd = events[i].data.fd) < 0)
                {
                    cout << "EPOLLIN sockfd < 0 error " << endl;
                    continue;
                }
                bzero(line, MAX_LINE);
                if((readlength = read(sockfd, line, MAX_LINE)) < 0){
                	if(errno == ECONNRESET){
                   		cout << "ECONNREST closed socket fd:" << events[i].data.fd << endl;
                        close(sockfd);
                	}
                }
                else if(readlength == 0){
                	epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                    close(events[i].data.fd);
                }
                else{
                	if(write(sockfd, line, readlength) != readlength)
                        cout << "error: not finished one time" << endl;
                }
			}
		}
	}
	close(sockfd);
	//close(clienfd);
	//return 0;
}