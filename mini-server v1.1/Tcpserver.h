//#include <iostream>
#pragma once 

#define MAX_EVENTS 100
#define MAX_LINE 20
#define MAX_FD 1000
#define MAX_LISTENFD 5


using namespace std;
class tcpserver
{
public:
	tcpserver(char* por) : port(por){}
	~tcpserver(){}
	void start();

private:
	int CreateAndListen(char * a);
	char* port;
};