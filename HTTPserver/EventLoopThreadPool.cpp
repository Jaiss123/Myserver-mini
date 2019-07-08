#include <vector>
#include "EventLoop.h"
#include "EventLoopThread.h"
#include "EventLoopThreadPool.h"
#include <iostream>


EventLoopThreadPool::EventLoopThreadPool(EventLoop* ploop, int threadnum = 0)
            :mainloop(ploop)
            ,iothreadnums(threadnum)
            ,index_(0)
{
    for(int i = 0; i < threadnum; i++){
        EventLoopThread* iothread = new EventLoopThread();
        threadlist_.push_back(iothread);
    }
}

EventLoopThreadPool::~EventLoopThreadPool()
{
    threadlist_.clear();
}

void EventLoopThreadPool::start()
{
    for(int i = 0; i < iothreadnums; i++)
        threadlist_[i]->Start();
}

EventLoop* EventLoopThreadPool::GetNextLoop()
{
    if(iothreadnums > 0)
    {
        //采用轮询进行IO操作
        EventLoop *loop = threadlist_[index_]->GetLoop();
        index_ = (index_ + 1) % iothreadnums;
        return loop;
    }
    else
    {
        return mainloop;
    }
}