
#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include "Declear.h"
#include "Define.h"
#include "IChannelCallback.h"

class Acceptor : public IChannelCallback
{
    public:
        Acceptor(EventLoop* pLoop);
        ~Acceptor();

        void start(char* port);
        void setCallback(IAcceptorCallback* pCallback);
        void virtual onIn(int socket);
    private:
        int createAndListen(char* port);
        int _listenfd;
        Channel* _pAcceptChannel;
        IAcceptorCallback* _pCallback;
        EventLoop* _pLoop;
};

#endif
