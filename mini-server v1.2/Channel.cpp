#include "Channel.h"
#include <sys/epoll.h>

channel::channel(int epollfd, int fd)
			:epoll_fd(epollfd),
			soketfd(fd),
			events_(0),
			revents_(0)
{

}


channel::~channel(){}

void channel::setCallback(channelCallBack* callback){
	callback_ = callback;
}

void channel::handle_event(){
	if(EPOLLIN & revents_)
		callback_->Func(soketfd);
}

void channel::set_Revents(int revents){
	revents_ = revents;
}

void channel::enableReading(){
	events_ = EPOLLIN;
	update();
}

void channel::update(){
	struct epoll_event ev;
	//将data.ptr 设置成当前channel指针
	//为将epoll返回的event数组直接将channel指针提取
	//方便了之后的回调方法的调用
	ev.data.ptr = this;
	ev.events = events_;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, soketfd, &ev);
}

