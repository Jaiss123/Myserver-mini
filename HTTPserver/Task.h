#ifndef TASK_H
#define TASK_H 

#include "HttpRequest.h"
#include "Declear.h"
#include <string>

class Task
{
    public:
        Task(IRun0* func);
        Task(IRun2* func, const std::string& str, void* param);
        Task(IRun0* func, int num);
        Task(IRun2* func, TcpConnection* Tcp, HttpRequest req, HttpContext* context_);
        void doTask();
    private:
        IRun0* _func0;
        IRun2* _func2;
        std::string _str;
        void* _param;
        int _num;
        TcpConnection* _Tcp;
        HttpRequest _req;
        HttpContext* context;
};

#endif
