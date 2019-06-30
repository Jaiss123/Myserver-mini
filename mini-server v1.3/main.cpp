//author voidccc
#include "TcpServer.h"
#include <iostream>

using namespace std;

int main(int args, char* argv[])
{
	if(args < 1){
		cout << "please input your argv: "<<endl;
		exit(0);
	}
    TcpServer tcpserver;
    tcpserver.start(argv[1]);
    return 0;
}
