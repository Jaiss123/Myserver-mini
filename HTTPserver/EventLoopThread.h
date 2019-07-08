#ifndef _EVENTLOOP_THREAD_H_
#define _EVENTLOOP_THREAD_H_

#include <iostream>
#include <string>
#include "Thread.h"
#include "EventLoop.h"
#include "IRun.h"

class EventLoopThread : public IRun0
{
private:
    //线程成员
    Thread* th_;

    //线程id
    pid_t threadid_;

    //线程名字
    std::string threadname_;

    //线程运行的loop循环
    EventLoop *loop_;

public:
    EventLoopThread();
    ~EventLoopThread();

    //获取当前线程运行的loop
    EventLoop* GetLoop();

    //启动线程
    void Start();

    //线程执行的函数
    void ThreadFunc();

    void run0();


    
    void run1(){};
};

#endif