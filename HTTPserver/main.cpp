#include "HttpServer.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "EventLoop.h"
#include "Timestamp.h"
#include <iostream>
#include <map>


int main(int argc, char* argv[])
{
  int numThreads = 0,iothreadnums = 0;
  if (argc > 1)
  {
    numThreads = atoi(argv[1]);
    iothreadnums = atoi(argv[2]);
  }
  EventLoop loop;
  HttpServer server(&loop, numThreads,iothreadnums);
  server.start();
  loop.loop();
}

