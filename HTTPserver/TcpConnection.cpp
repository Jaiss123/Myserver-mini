#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include "TcpConnection.h"
#include "Channel.h"
#include "EventLoop.h"
#include "Define.h"
#include "IMuduoUser.h"
#include "Task.h"
#include "Timestamp.h"
#include "CurrentThread.h"
#include <string.h> //for bzero
#include <iostream>
using namespace std;

TcpConnection::TcpConnection(int sockfd, EventLoop* pLoop)
    :_sockfd(sockfd)
    ,_pLoop(pLoop)
    ,_pUser(NULL)
{
    _pSocketChannel = new Channel(_pLoop, _sockfd); // Memory Leak !!!
    _pSocketChannel->setCallback(this);
    if(this == 0)
        cout << "99999999999" <<endl;
    _pSocketChannel->enableReading();
}

TcpConnection::~TcpConnection()
{}

void TcpConnection::handleRead()
{
    int sockfd = _pSocketChannel->getfd();
    int readlength;
    char line[MAX_LINE];
    if(sockfd < 0)
    {
        //cout << "EPOLLIN sockfd < 0 error " << endl;
        return;
    }
    bzero(line, MAX_LINE);
    if((readlength = read(sockfd, line, MAX_LINE)) < 0)
    {
        if(errno == ECONNRESET)
        {
            cout << "ECONNREST closed socket fd:" << sockfd << endl;
            close(sockfd);
        }
    }
    else if(readlength == 0)
    {
        //cout << "read 0 closed socket fd:" << sockfd << endl;
        close(sockfd);
    }
    else
    {
        string linestr(line, readlength);
        _inBuf.append(linestr);
        //cout << this <<endl;
        _pUser->onMessage(this, &_inBuf, Timestamp::now());
    }
}

void TcpConnection::handleWrite()
{
    int sockfd = _pSocketChannel->getfd();
    if(_pSocketChannel->isWriting())
    {
        int n = ::write(sockfd, _outBuf.peek(), _outBuf.readableBytes());
        if( n > 0)
        {
            cout << "write " << n << " bytes data again" << endl;
            _outBuf.retrieve(n);
            if(_outBuf.readableBytes() == 0)
            {
                _pSocketChannel->disableWriting(); //remove EPOLLOUT
                Task task(this);
                _pLoop->queueInLoop(task); //invoke onWriteComplate
            }
        }
    }
}

void TcpConnection::send(const string& message)
{
    if(_pLoop->isInLoopThread()) //is thread of loop
    {
        sendInLoop(message);
    }
    else
    {
        Task task(this, message, this);
        _pLoop->runInLoop(task);
    }
}

void TcpConnection::sendInLoop(const string& message)
{
    int n = 0;
    //cout << "sendinloop"<<endl;
    if(_outBuf.readableBytes() == 0)
    {
        n = write(_sockfd, message.c_str(), message.size());
        if(n < 0)
        {
            if (errno == EAGAIN)//系统缓冲区满，非阻塞返回
			{
				std::cout << "write errno == EAGAIN,not finish!" << std::endl;
				return ;
			}
			else if (errno == EINTR)
			{
				std::cout << "write errno == EINTR" << std::endl;
				//continue;
			}
			else if (errno == EPIPE)
			{
				//客户端已经close，并发了RST，继续wirte会报EPIPE，返回0，表示close
				perror("write error");
				std::cout << "write errno == client send RST" << std::endl;
				return ;
			}
			else
			{
				perror("write error");//Connection reset by peer
				std::cout << "write error, unknow error" << std::endl;
				close(_sockfd);
			}
        }
        if(n == static_cast<int>(message.size()))
        {
            Task task(this);
            _pLoop->queueInLoop(task); //invoke onWriteComplate
        }
    }

    if( n < static_cast<int>(message.size()))
    {
        try{
            n = n > 0? n : 0;
            _outBuf.append(message.substr(n, message.size()));
        }
        catch(...){
            cerr << message << endl;
        }
        if(!_pSocketChannel->isWriting())
        {
            _pSocketChannel->enableWriting(); //add EPOLLOUT
        }
    }
}

void TcpConnection::connectEstablished()
{
    if(_pUser)
        _pUser->onConnection(this);
}

void TcpConnection::setUser(IMuduoUser* user)
{
    _pUser = user;
}


void TcpConnection::shutdown()
{
    Task task(this,1);  //调用 run1
    _pLoop->runInLoop(task);
}

void TcpConnection::run0()
{
    _pUser->onWriteComplate(this);
}

void TcpConnection::run1()
{
    if(_pLoop->isInLoopThread()) //is thread of loop
    {
        if (!_pSocketChannel->isWriting())
        {
            ::shutdown(_sockfd, SHUT_WR);   //断开输出流
            //close(_sockfd);
        }
    }
}

void TcpConnection::run2(const string& message, void* param)
{
    sendInLoop(message);
}
