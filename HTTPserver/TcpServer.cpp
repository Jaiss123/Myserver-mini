#include <errno.h>
#include "TcpServer.h"
#include "Channel.h"
#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoopThreadPool.h"
#include <vector>

TcpServer::TcpServer(EventLoop* pLoop, int iothreadnum)
    :_pAcceptor(NULL)
    ,_pLoop(pLoop)
    ,_pUser(NULL)
    ,loopthreadpool(pLoop,iothreadnum)
{
}

TcpServer::~TcpServer()
{
}

void TcpServer::start()
{
    loopthreadpool.start();         //开启io线程池

    _pAcceptor = new Acceptor(_pLoop); // Memory Leak !!!
    _pAcceptor->setCallback(this);
    _pAcceptor->start();
}

void TcpServer::newConnection(int sockfd)
{
    EventLoop* ioloop = loopthreadpool.GetNextLoop();
    TcpConnection* tcp = new TcpConnection(sockfd, ioloop); // Memory Leak !!!
    _connections[sockfd] = tcp;
    tcp->setUser(_pUser);
    tcp->connectEstablished();

   
}

void TcpServer::setCallback(IMuduoUser* user)
{
    _pUser = user;
}
