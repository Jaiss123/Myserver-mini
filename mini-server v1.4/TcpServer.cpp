

#include <errno.h>

#include "TcpServer.h"
#include "Channel.h"
#include "Acceptor.h"
#include "TcpConnection.h"

#include <vector>
#include <iostream>

using namespace std;

TcpServer::TcpServer(EventLoop* loop)
    :_pAcceptor(NULL)
    ,_loop(loop)
{
}

TcpServer::~TcpServer()
{
}

void TcpServer::start(char* port)
{
    _pAcceptor = new Acceptor(_loop); // Memory Leak !!!
    _pAcceptor->setCallBack(this);
    _pAcceptor->start(port);
}

void TcpServer::newConnection(int sockfd)
{
    TcpConnection* tcp = new TcpConnection(sockfd, _loop); // Memory Leak !!!
    _connections[sockfd] = tcp;
}
