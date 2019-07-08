#ifndef _EVENTLOOPTHREADPOOL_H
#define _EVENTLOOPTHREADPOOL_H

#include "EventLoop.h"
#include "EventLoopThread.h"
#include <vector>



class EventLoopThreadPool
{
private:
  //主loop
  EventLoop *mainloop;

  //io线程数量
  int iothreadnums;

  //线程列表
  std::vector<EventLoopThread*> threadlist_;

  //索引
  int index_;


public:
  EventLoopThreadPool(EventLoop* ploop, int threadnum);
  ~EventLoopThreadPool();

  void start();
  EventLoop* GetNextLoop();
};








#endif