//author voidccc
#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include "Declear.h"
#include "Define.h"
#include "IChannelCallBack.h"

class Acceptor : public IChannelCallBack
{
    public:
        Acceptor(EventLoop* loop);
        ~Acceptor();

        void start(char* port);
        void setCallBack(IAcceptorCallBack* pCallBack);
        void virtual OnIn(int socket);
    private:
        int createAndListen(char* port);
        int _listenfd;
        Channel* _pAcceptChannel;
        IAcceptorCallBack* _pCallBack;
        EventLoop* _loop;
};

#endif
