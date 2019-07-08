#include "EventLoopThread.h"
#include <iostream>
#include <sstream>
#include "Task.h"
#include "CurrentThread.h"
#include "Thread.h"

EventLoopThread::EventLoopThread()
    : threadname_("IO thread "),
    loop_(NULL)
{
    Task task(this);
    th_ = new Thread(task);
}

EventLoopThread::~EventLoopThread()
{
    //线程结束时清理
    std::cout << "Clean up the EventLoopThread id: " << CurrentThread::tid() << std::endl;
    //loop_->Quit();//停止IO线程运行
    th_->join();//清理IO线程，防止内存泄漏，因为pthread_created回calloc
}

EventLoop* EventLoopThread::GetLoop()
{
    return loop_;
}
void EventLoopThread::Start()
{
    //create thread
    th_ ->start();
}

void EventLoopThread::ThreadFunc()
{
    EventLoop loop;
    loop_ = &loop;

    threadid_ = th_->gettid();
    std::stringstream sin;
    sin << threadid_;    
    threadname_ += sin.str();

    std::cout << "in the thread:" << threadname_ << std::endl;   
    try
    {
        //std::cout << "EventLoopThread::ThreadFunc " << std::endl;
        loop_->loop();
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught in EventLoopThread::ThreadFunc loop: " << ba.what() << '\n';
    }
    //loop_->loop();
}

void EventLoopThread::run0()
{
    ThreadFunc();           
}


