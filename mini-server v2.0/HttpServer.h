#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "IMuduoUser.h"
#include "IRun.h"
#include "TcpServer.h"
#include "ThreadPool.h"
#include "Declear.h"

class HttpServer : public IMuduoUser
                   , public IRun2
{
public:
    HttpServer(EventLoop* pLoop, int threadnums);
    ~HttpServer();
    void start();
    

    virtual void onConnection(TcpConnection* pCon);
    virtual void onMessage(TcpConnection* pCon, Buffer* pBuf, Timestamp receiveTime);
    virtual void onWriteComplate(TcpConnection* pCon);
    virtual void onRequest(TcpConnection* pCon, HttpRequest& req);
    virtual void run3(TcpConnection* pCon, HttpRequest req, HttpContext* context);
    virtual void run2(const string& str, void* tcp);

private:
    EventLoop* _pLoop;
    TcpServer _pServer;
    ThreadPool _threadpool;

    int _timer;
    int _index;
    int _threadnums;
};

#endif
