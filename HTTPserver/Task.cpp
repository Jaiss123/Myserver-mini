#include "Task.h"
#include "Declear.h"
#include "IRun.h"
#include "HttpContext.h"
#include "HttpRequest.h"

Task::Task(IRun0* func)
    :_func0(func)
    ,_func2(NULL)
    ,_param(NULL)
    ,_num(0)
{

}

Task::Task(IRun2* func, const string& str, void* param)
    :_func0(NULL)
    ,_func2(func)
    ,_str(str)
    ,_param(param)
    ,_num(0)
    ,_Tcp(NULL)
{

}

Task::Task(IRun0* func, int num)
    :_func0(func)
    ,_func2(NULL)
    ,_num(num)
{
    
}

Task::Task(IRun2* func, TcpConnection* Tcp, HttpRequest req, HttpContext* context_)
    :_func0(NULL)
    ,_func2(func)
    ,_str("")
    ,_Tcp(Tcp)
    ,_req(req)
    ,context(context_)
{

}

void Task::doTask()
{
    if(_func0) {
        if(_num != 0){
            _func0->run1();
        }
        else
        {
            _func0->run0();
        }
        
        
    } else {
        if(_str != "")
            _func2->run2(_str, _param);
        else
            _func2->run3(_Tcp,_req,context);
    }
}
