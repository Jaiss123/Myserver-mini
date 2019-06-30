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
#include "Channel.h"
#include <vector>


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

	if(-1 == bind(serverfd,(struct sockaddr*)&servaddr,sizeof(servaddr))){
		cout << "bind error, errno: "<<errno<<endl;
		return -1;
	}
	if(-1 == listen(serverfd,MAX_LISTENFD)){
		cout << "listen error,errno:" << errno <<endl;
		return -1;
	}

	return serverfd;	

}

void tcpserver::Func(int sockfd){
	cout << "Func:"<< sockfd << endl;
	if(sockfd == serverfd){
		struct sockaddr_in cliaddr;
        socklen_t clilen = sizeof(struct sockaddr_in);
		int clienfd = accept(serverfd, (sockaddr*)&cliaddr, (socklen_t*)&clilen);
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
                 return;
		}

		//将新的socket加入到epoll的监听范围
		fcntl(clienfd, F_SETFL, O_NONBLOCK);
		
        channel* pChannel = new channel(epoll_fd, clienfd);
        pChannel->setCallback(this);
        pChannel->enableReading();
	}
	else{
		int readlength = 0;
		char line[MAX_LINE];
		if(sockfd < 0)
        {
            cout << "EPOLLIN sockfd < 0 error " << endl;
            return ;
        }
        bzero(line, MAX_LINE);
        if((readlength = read(sockfd, line, MAX_LINE)) < 0){
        	if(errno == ECONNRESET){
           		cout << "ECONNREST closed socket fd:" << sockfd << endl;
                close(sockfd);
        	}
        }
        else if(readlength == 0){
        	cout << "Client closed socket fd:" << sockfd << endl;
        	epoll_ctl(epoll_fd, EPOLL_CTL_DEL, sockfd, NULL);
            close(sockfd);
        }
        else{
        	if(write(sockfd, line, readlength) != readlength)
                cout << "error: not finished one time" << endl;
        }
	}
}


void tcpserver::start(){


	epoll_fd = epoll_create(MAX_EVENTS);
	if(epoll_fd < 0)
		cout << "epoll_create error,error:"<< epoll_fd <<endl;
	serverfd = CreateAndListen(port);
	if(-1 == serverfd){
		return;
	}

	/*ev.data.fd = serverfd;
	ev.events = EPOLLIN;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, serverfd, &ev);*/

	//通过channel类来管理serverfd
	channel pchannel(epoll_fd, serverfd);
	pchannel.setCallback(this);
	pchannel.enableReading();

	while(1){

		activechannels.clear();
		int num_fds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
		
		/*打印操作符****************************/
		cout <<"监听到的描述符有： ";
		for (int i = 0; i < num_fds; ++i)
		{
			cout << (static_cast<channel*>(events[i].data.ptr))->get_socktfd() << " ";
		}
		cout << endl;
		/*************************************/

		if(num_fds == -1){
			cout << "epoll_wait error: errno" << errno << endl;
			break;
		}

		for(int i = 0; i < num_fds; i++ )
		{
			//通过EPOLL取出感兴趣的channel
			channel	* onechannel = static_cast<channel*>(events[i].data.ptr);
			onechannel->set_Revents(events[i].events);
			activechannels.push_back(onechannel);
		}

		for(auto onechannel : activechannels){
			onechannel->handle_event();
		}

	}
	close(serverfd);

}