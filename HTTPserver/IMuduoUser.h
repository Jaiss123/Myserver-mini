#ifndef IMUDUOUSER_H
#define IMUDUOUSER_H

#include "Declear.h"
#include <string>
using namespace std;

class IMuduoUser
{
    public:
        virtual void onConnection(TcpConnection* pCon) = 0;
        virtual void onMessage(TcpConnection* pCon, Buffer* pBuf, Timestamp receiveTime) = 0;
        virtual void onWriteComplate(TcpConnection* pCon) = 0;
        virtual void onRequest(TcpConnection* pCon, HttpRequest& req) = 0;
};

#endif
