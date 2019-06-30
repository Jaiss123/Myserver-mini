# 项目名称：Myserver-mini
自己写的一个高并发服务器，正在进行中

编写服务器的过程中主要参考了陈硕的《C++多线程服务器编程》和 网上一位博主大佬 voidccc 的博客 https://blog.csdn.net/solstice/

看完muduo网络库的我在仰望大佬的同时，深深的感觉到了与大佬的差距，怒从零写一个server！！！！希望可以在复现muduo库主要功能的同时对其进行改进。

# 前言

前面服务器版本的测试均采用统一的客户端client 和 回声服务端server 编译：echo_client.cpp，直接执行可执行文件 ./client 即可。

客户端使用示例：
```c
./client 127.0.0.1 9190
```
服务端使用示例：

```c
./server 9190
```
回声服务器运行：

![Image_text](https://github.com/Jaiss123/Myserver-mini/blob/master/1.png)


# 0 Myserver-mini-v1.0

1. 使用 **epoll/无阻塞**的方式实现了一个echosever

2. 程序说明： **epoll**的API

```cpp
//使用epoll的三个函数
int epoll_create(int size) 创建一个epoll文件描述符

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event) 将socket描述符加入/移出epoll监听，修改注册事件

int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout) 在epoll描述符上等待事件的发生，并获得事件
```
使用fcnt将socket设置成无阻塞模式

# 1 Myserver-mini-v1.1

1. 添加了**Tcpserver**类，用来对socket的`bind，listen和accept`进行封装。完成对reactor模式构建的第一步。

# 2 Myserver-mini-v1.2

1. 介绍一下`Channel`类，先看其声明，这里特别要注意`events_`和`revents_`，前者是要关注的事件，后者是发生的事件，不仔细看容易混淆。名字的来源是poll(2)的`struct pollfd`。

2. `channel`对象自始至终只负责一个文件描述符的IO事件分发，将`epoll`的监控与事件响应分开执行。在之前的V1.1 v1.0版本中，epoll监控到描述符的变化时，就进行read或者write操作；使用channel后将事件的回调放到channel中管理。

3. 需要注意的是muduo库的回调时采用boost::bind()对函数进行显式的回调，我们这里采用**虚函数的方法**，回调时直接传入基类对象，回调调用具体对象相应的func函数，所以如下:

```cpp
 struct epoll_event ev;
 ev.data.ptr = this;
 ev.events = _events;
 epoll_ctl(_epollfd, EPOLL_CTL_ADD, _sockfd, &ev);
```
添加的epoll_event结构体中传递的是channel* 指针，而不是fd，传什么都行，data是一个union，这样做就是为了发生事件时，可以直接调用channel

# 3 Myserver-mini-v1.3

1. 本版本添加了两个类 `Acceptor` 和 `Tcpconnection` 两个类，`Acceptor` 用来处理来自 `server` 的连接请求以及连接操作，`Tcpconnection` 用来处理来自客户端client 的请求和操作。

2. 与上一个版本不同的是，所有的回调函数都是在 `Tcpserver` 类中的`Func`中完成的，而目前的版本是将回调函数 Func 放到相应的 `Acceptor` 和 `Tcpconnection` 中，实现了**“连接”和“读写”**的分离。这也是应该的，因为接受连接和读写数据根本就是两种性质的事件，处理方式也完全不同，理应放到两个不同的类中。

3. `Acceptor` 类的作用就是处理新连接，`Acceptor` 里的 `Channel` 关注着用于listen的socket，一旦有连接到达，就将连接accept下来。注意accept后还有个重要的步骤，就是回调一下 TcpServer，使得后者有机会创建 TcpConnection（这里为什么不直接在 Acceptor 里新建 `TcpConnection` 而是将其放到 `TcpServer` 里，我想在逻辑上新socket建立后就和之前用于 `listen` 的 socket 没有任何关系了，`TcpConnection 和 Acceptor` 分别关心不同的 socket 上的不同事件，这两个类是平行的关系，如果前者创建后者，又牵扯生命周期的管理逻辑上不太合适，由 `TcpServer` 来掌握两者的生命周期更合适些）

**总结：** 该版本目前已经能够将最基本的 reactor 模型建立出来了，之后再将 epoll 和 Tcpserver 中的 loop 分离开来

# 4 Myserver-mini-v1.4

1. 这个版本最最要的是加入了两个类**EventLoop** 和 **Epoll**，这两个类的加入就把我们之前I/O服用的最基本的流程全都拆成一块一块的了，更加的便于维护，程序代码逻辑也就相对清晰了。

2. 相对最开始v1.0版本，**epoll_create /epoll_ctl / epoll_wait** 全都放到了 epoll.cpp 文件处理，**socket/ bind / listen/ accept** 函数全都放到了 Acceptor 中处理了，for循环遍历的过程交给 EventLoop 来处理，客户端操作 `read/write` 交给`Tcpconnection`处理。

* 先来看**EventLoop**，根据名字可以猜测这个类的作用是事件循环，其实这个类就是用来包装 for 循环的，也就是那个套在**epoll_wait**外面的 for 循环，这个 for 循环可以说是整个程序最核心的部分，for循环等待在 **epoll_wait** 上，然后遍历返回的每个事件，先通知到 **Channel**，然后由 **Channel** 通知到最终的事件处理程序（位于 `Acceptor` 和 `TcpConnection` 中）。在上一个版本中。for 循环位于 TcpServer 里，现在我们把它移动到 EventLoop 的 loop 方法里，用while 代替for，作用跟之前的for循环一样：等待在 **epoll_wait** 上，当有事件发生时，回调 Channel。当然，EventLoop::loop() 不是直接调用 epoll_wait，而是使用了其包装类 Epoll。

* **Epoll** 类的作用是包装 **epoll** 文件描述符，它最重要的成员变量是一个 **epoll** 文件描述符，最重要的两个方法是 **poll** 和 **update**。poll 方法包装了**epoll_wait**，在 **epoll** 描述符上等待事件的发生，当有事件发生后将新建的**Channel** 填充到 **vector** 中，**update** 方法包装了 **epoll_ctl**，用来在 epoll 文件描述符上添加/修改/删除事件。update接收一个 Channel 作为参数，通过这个 Channel 可以获得要注册的事件(**Channel::getEvents()**方法)。以后所有涉及 epoll 描述符的操作都通过 **Epoll** 的这两个方法来完成。**EventLoop** 本来是应该包括一个 epoll 描述符的，loop 方法通过一个循环来调用 epoll_wait，而现在 epoll 描述符在**Epoll**中，所以** EventLoop** 只需要包含一个 Epoll 成员变量即可。EventLoop 在循环中只需要调用 Epoll::poll() 方法就可以获得Channel列表，不需要直接调用 epoll_wait 了。

# 5 Myserver-mini-v1.5

1. 增加了基类 **IMuduoUser**，代表该库的用户，其中EchoSever代表这个类的用户，用户关心的是接到客户端的数据后如何处理，然后返回什么内容给客户端。 而库要做的是顺利接收客户端数据，并将收到的数据送给用户处理，同时在用户发出发送指令后能将数据完整的发送给客户端。作为 mini-server 的用户，必须实现IMuduoUser接口，这个接口是网络库和用户之间的桥梁。

* **IMuduoUser**里目前有两个纯虚函数，**onConnection和onMessage**，分别在连接建立和收到数据的时候被调用，目前**IMuduoUser**接口还有两个地方待完善，第一，还有一个重要的接口没有加进来，那就是**onWriteComplate**。这个回调会在后面版本加入进来，到时再详细介绍。第二，onMessage回调的参数还很原始，**onMessage**担负着输送数据给用户的重任，当前版本只用了一个**const string&**来表示数据而不像muduo一样有专门的Buffer类，这个缺陷也会在后面版本得到完善。观察**IMuduoUser**的两个方法，发现都将**TcpConnection**传递给了用户，是的，这个类以后就是用户的指挥棒了，用户想发送数据或者做点别的操作，都是通过**TcpConnection**来完成的。目前最重要的就是send方法。

2. 因为响应请求的过程从**TcpConnection**移动到了**EchoServer**中，所以**TcpConnection**也做了相应更改，在原来的onIn方法里不再直接调用write将数据传回，而是在其中调用了其保存的**IMuduoUser::onMessage**方法将数据传递给了Muduo网络库的真正用户。同时**TcpConnection**增加了一个send方法，这个方法包装了write操作，提供给网络库的用户来使用。**onMessage()**方法的参数里会传递**TcpConnection** 给用户，用户可以自行决定是否发送数据。

# 6 Myserver-mini-v1.6

1. 在tcp的通信过程中，内核其实为tcp维护着一个缓冲区 当调用**write/send**时，会向内核缓冲区中写入数据，内核和tcp协议栈负责将缓冲区中的数据发送到指定<ip，port>的目标位置。 当有数据到达内核的tcp缓冲区中，如果开启了对套接字可读事件的监听，那么内核会让套接字变为可读状态，从而从poll函数中返回，调用read/recv进行读操作。

2. 但是，内核维护的tcp缓冲区通常都比较小: 
* 如果调用write/send时，内核缓冲区已满，那么阻塞io将会阻塞在io函数上直到内核缓冲区有足够的空间容纳要写入的数据，非阻塞io将会返回错误，通常是`EAGAIN/EWOULDBLOCK`。

* 如果调用write/send时，内核缓冲区未满，但是不能容纳要写入的字节数，可用空间不足，那么只会写入能写入的那么多字节数，此时，仍然有一些数据没有发送，可是这些数据还非发送不可，就出现缓冲区已满的情况。这就导致要不阻塞当前线程，要不无法正常写入数据，而如果采用判断返回值是否出错的方法，仍然是一直忙循环检测io写入状态，仍然是busy loop，仍然会阻塞当前线程

3. 而且，io多路复用分水平触发和边缘触发两种，当内核tcp缓冲区中一直有数据时:

* 如果是水平触发，那么套接字会一直处于可读状态，io多路复用函数会一直认为这个套接字被激活，也就是说如果第一次触发后没有将tcp缓冲区中的数据全部读出，那么下次进行到poll函数时会立即返回，因为套接字一直是可读的。这会导致了busy loop问题

* 如果是边缘触发，那么就只会触发一次，即使第一次触发没有将所有数据都读走，下次进行到poll也不会再触发套接字的可读状态，直到下次又有一批数据送至tcp缓冲区中，才会再次触发可读。所以有可能存在漏读数据的问题，万一不会再有数据到来呢，此时tcp缓冲区中仍然有数据，而应用程序却不知道所以，设计应用层自己的缓冲区是很有必要的，也就是由应用程序来管理缓冲区问题

4. 应用层缓冲区通常很大，也可以初始很小，但可以通过动态调整改变大小（vector）,我这里目前使用的是string设计的双缓冲队列。

应用层缓冲区需要有读/写两个（缓冲区类只有一个，既可被用作读缓冲区，也可被用作写缓冲区）当用户想要调用write/send写入数据给对端，如果数据可以全部写入，那么写入就好了。如果写入了部分数据或者根本一点数据都写不进去，此时表明内核缓冲区已满，为了不阻塞当前线程，应用层写缓冲区会接管这些数据，等到内核缓冲区可以写入的时候自动帮用户写入。

当有数据到达内核缓冲区，应用层的读缓冲区会自动将这些数据读到自己那里，当用户调用read/recv想要读取数据时，应用层读缓冲区将已经从内核缓冲区取出的数据返回给用户，实际上就是用户从应用层读缓冲区读取数据应用层缓冲区对用户而言是隐藏的，用户可能根本不知道有应用层缓冲区的存在，只需读/取数据，而且也不会阻塞当前线程

以read操作为例：

```cpp
void TcpConnection::handleRead()
{
    int sockfd = _pChannel->getSockfd();
    int readlength;
    char line[MAX_LINE];
    if(sockfd < 0)
    {
        cout << "EPOLLIN sockfd < 0 error " << endl;
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
        cout << "read 0 closed socket fd:" << sockfd << endl;
        close(sockfd);
    }
    else
    {
        string linestr(line, readlength);
        _inBuf.append(linestr);
        _pUser->onMessage(this, &_inBuf);
    }
}
```
当从内核缓存read到一些数据时，我们要把读到的数据append到应用层缓冲区_inbuf末尾，然后可以调用用户的处理函数 onMessage() 对接收到的数据进行处理。

# 7 Myserver-mini-v1.7

1. 1.7版本在IMuduoUser中增加了onWriteComplate回调。这样当用户一次传送大量数据到网络库时，用户会在数据发送完成后收到通知。

* 下面对 IMuduoUser进行说明：
```
先来看看IMuduoUser的onWriteComplate回调，首先要明确的是onWriteComplate回调什么时候会被调用，那就是用户递交数据给网络库，当网络库把这些信息全部传送给操作系统后(通过::write()调用)，用户对象的onWriteComplate会被回调到。muduo使用的是level triger的Epoll，所以应该在下面两个位置调用onWriteComplate。注意这两处不是直接通过_pUser->onWriteComplate(this);的方式调用的，而是使用了EventLoop::queueLoop方法来异步调用。下条说明会对queueLoop方法做详细介绍。在原始muduo里关于这个回调的讲解可参见<<LInux多线程服务端编程>>P322页。

```
第一次调用：在send发送的时候，当前发送缓冲为0，且数据通过write函数一次性发送完。
```cpp
void TcpConnection::send(const string& message)
{
     int n = 0;
     if(_outBuf.readableBytes() == 0)
     {
         n = ::write(_sockfd, message.c_str(), message.size());
         if(n < 0)
             cout << "write error" << endl;
         if(n == static_cast<int>(message.size()))
             _pLoop->queueLoop(this); //invoke onWriteComplate
     }
 
     if( n < static_cast<int>(message.size()))
     {
         _outBuf.append(message.substr(n, message.size()));
         if(_pChannel->isWriting())
         {
             _pChannel->enableWriting(); //add EPOLLOUT
         }
     }
 }
```
当操作系统的发送缓冲区有更多可用空间时，通过让epoll_wait返回来通知我们发生了EPOLLOUT事件，这时网络库会把自己保存缓冲区数据继续送给操作系统，如果全部数据操作系统都接收完毕，这时也需要通知用户了。
```cpp
void TcpConnection::handleWrite()
 {
     int sockfd = _pChannel->getSockfd();
     if(_pChannel->isWriting())
     {
         int n = ::write(sockfd, _outBuf.peek(), _outBuf.readableBytes());
         if( n > 0)
         {
             cout << "write " << n << " bytes data again" << endl;
             _outBuf.retrieve(n);
             if(_outBuf.readableBytes() == 0)
             {
                 _pChannel->disableWriting(); //remove EPOLLOUT
                 _pLoop->queueLoop(this); //invoke onWriteComplate
             }
        }
     }
 }
```
2. EventLoop::queueLoop()方法：这是一个非常重要的方法。在没有这个方法之前，我们使用 epoll_wait() 接收的所有事件，都是来自操作系统的，比如EPOLLIN/EPOLLOUT，我们使用epollfd只是用来接收操作系统的网络通知。现在我们需要让 epollfd 多做点事情，让他能接收网络库自己发送的通知。这种通知有两个重要的价值：

 * 使得网络库内部在单线程的情况下具备异步处理事件的能力。
 
 * 使得网络库的IO线程(跑epoll_wait的那个线程)，可以接收来自非本线程的发送请求。
 
3. 这种通知是通过 eventfd来实现的, 本质上也是一个socket描述符，只不过有自己的创建方式,不需要ip及端口来连接：

```cpp
int EventLoop::createEventfd()
{
  int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
  if (evtfd < 0)
  {
      cout << "Failed in eventfd" << endl;
  }
  return evtfd;
}
```
* eventfd 可以像 socket 一样被 epollfd 所监听，如果向eventfd写点东西，epoll就会获得这个通知并返回。EventLoop正是通过封装eventfd才获得了异步处理能力。

* 真正的事件处理过程位于EventLoop::loop()方法中，新添加的EventLoop::doPendingFunctors()方法正是用来触发异步调用的。

4. 现在重新理顺一下EventLoop::queueLoop()方法的实现，这个方法其实就是先将一个代表回调的IRun* 放入到EventLoop的vector中保存，然后就触发eventfd的事件，本次循环完毕，当下次 EventLoop::loop 循环到epoll_wait时，会因为eventfd的触发而返回，这时eventfd对应的Channel会被通知，进而通知到EventLoop::handleRead 方法，我们在里面把事件读出来，这样确保事件只触发一次。EventLoop::loop循环会继续调用到doPendingFunctors() 方法，这里面遍历保存 IRun* 的vector，于是所有异步事件就开始处理了。

**注意：**doPendingFunctors方法的实现，这里不是通过简单的遍历vector来调用回调，而是新建了一个vector，然后调用vector::swap方法将数组交换出来后再调用，这么做的目的是“减小临界区的长度和避免死锁”，在<<Linux多线程服务器端编程>>P295页有详细介绍。当然我们的mini-muduo目前还是单线程，影响不大。





