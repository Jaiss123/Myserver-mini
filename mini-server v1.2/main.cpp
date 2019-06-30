#include "Tcpserver.h"



int main(int argc, char* argv[]){
	tcpserver tcp(argv[1]);
	tcp.start();

	return 0;
}
