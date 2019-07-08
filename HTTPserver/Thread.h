#ifndef THREAD_H
#define THREAD_H

#include "Declear.h"
#include "Task.h"
#include <pthread.h>

class Thread
{
    public:
        Thread(Task& task);
        void start();
        pid_t gettid();
        void join();
    private:
        Task _task;
        pthread_t t;
};

#endif
