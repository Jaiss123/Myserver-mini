#pragma once
#include "channelCallBack.h"

class channel
{
public:
	channel(int epollfd, int fd);
	~channel();

	void setCallback(channelCallBack* callback);
	void handle_event();
	void set_Revents(int events);
	void enableReading();
	int get_socktfd(){ return soketfd;}


private:
	void update();

	channelCallBack* callback_;

	int events_;
	int epoll_fd;
	int soketfd;
	int revents_;

};