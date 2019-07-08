#ifndef HTTPSERVER_H
#define HTTPSERVER_H


#include "TcpConnection.h"
#include "TcpServer.h"
#include "ThreadPool.h"
#include <unordered_set>
#include <boost/circular_buffer.hpp>
#include <iostream>


struct Entry 
{

 public:   
    explicit Entry(TcpConnection*& Conn)
    : _Conn(Conn)
    {
    }

    ~Entry()
    {
        //std::cout<<"~Entry" <<endl;
        if (_Conn)
        {
            _Conn->shutdown();
        }
    }

    TcpConnection* _Conn;
};



class HttpServer : public IMuduoUser
                   , public IRun2
                   , public IRun0
{
public:
    HttpServer(EventLoop* pLoop, int threadnums, int iothreadnums);
    ~HttpServer();
    void start();
    

    virtual void onConnection(TcpConnection* pCon);
    virtual void onMessage(TcpConnection* pCon, Buffer* pBuf, Timestamp receiveTime);
    virtual void onWriteComplate(TcpConnection* pCon);
    virtual void onRequest(TcpConnection* pCon, HttpRequest& req);
    virtual void run3(TcpConnection* pCon, HttpRequest req, HttpContext* context);
    virtual void run2(const string& str, void* tcp);
    virtual void run0();
    virtual void run1(){};
    
    

private:
    EventLoop* _pLoop;
    TcpServer _pServer;
    ThreadPool _threadpool;

    int _timer;
    int _index;
    int _threadnums;

    typedef std::shared_ptr<Entry> EntryPtr;
    typedef std::weak_ptr<Entry> WeakEntryPtr;
    typedef std::unordered_set<EntryPtr> Bucket;
    typedef boost::circular_buffer<Bucket> WeakConnectionList;

    void dumpConnectionBuckets() const;

    WeakConnectionList connectionBuckets_;
};

#endif
