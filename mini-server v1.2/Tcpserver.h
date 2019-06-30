
#pragma once 

#include <sys/epoll.h>
#include <vector>
#include "channelCallBack.h"
#include "Channel.h"


#define MAX_EVENTS 100
#define MAX_LINE 20
#define MAX_FD 1000
#define MAX_LISTENFD 5


using namespace std;
class tcpserver : public channelCallBack
{
public:
	tcpserver(char* por) : port(por),epoll_fd(-1),serverfd(-1){}
	~tcpserver(){}
	void start();
	void Func(int sockfd);
private:
	int CreateAndListen(char * a);
	char* port;
	vector<channel*> activechannels;
	int serverfd;
	int epoll_fd;
	struct epoll_event events[MAX_EVENTS];

};