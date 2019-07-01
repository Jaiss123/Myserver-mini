#ifndef IRUN_H
#define IRUN_H

#include <string>
#include "Declear.h"
using namespace std;

class IRun0
{
    public:
        virtual void run0() = 0;
        virtual void run1() = 0;
};

class IRun2
{
    public:
        virtual void run2(const string& str, void* param) = 0;
        virtual void run3(TcpConnection* pCon, HttpRequest req, HttpContext* context) = 0;
};

#endif
