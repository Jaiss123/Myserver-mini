#include "httpServer.h"
#include "TcpConnection.h"
#include "EventLoop.h"
#include "CurrentThread.h"
#include "Task.h"
#include "HttpContext.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Timestamp.h" 

#include <iostream>

#define MESSAGE_LENGTH 8

char favicon[555];

const string index0fhtml = "<html lang = \"zh-CN\"><head><title>月光骆驼主页</title>\
            <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /></head>\
            <body><h1>欢迎来到我的个人网页</h1>\
            <p><font size=\"4\" color=\"black\"><strong>2019年华为软件精英挑战赛，京津东北赛区初赛第13，复赛第18，呦车还没我跑的快。</strong></font></p>\
            <p>  <font color=\"black\" size=\"4\">历时一个多月的华为软件精英大赛落下帷幕，很遗憾的止步了三十二强，从初赛到复赛更改了大大小小的版本将近50多个，通过改进调度算法、发车策略、路权系数、架构等几方面对自己的算法进行了无数次的改进。终于抽出时间把自己的算法整理一下：</font></p>\
            </body></html>";

//具体回应的协议：请求行 请求头 请求内容
void dohttprequest(const HttpRequest& req, HttpResponse* resp)
{
    std::cout << "Headers " << req.methodString() << " " << req.path() << std::endl;

    const std::map<string, string>& headers = req.headers();
    for (const auto& header : headers)
    {
    std::cout << header.first << ": " << header.second << std::endl;
    }


    if (req.path() == "/")
    {
        resp->setStatusCode(HttpResponse::k200Ok);
        resp->setStatusMessage("OK");
        resp->setContentType("text/html");
        resp->addHeader("Server", "Muduo");
        string now = Timestamp::now().toFormattedString(1);
        resp->setBody(index0fhtml);
    }
    else if (req.path() == "/favicon.ico")
    {
        resp->setStatusCode(HttpResponse::k200Ok);
        resp->setStatusMessage("OK");
        resp->setContentType("image/png");
        resp->setBody(string(favicon, sizeof favicon));
    }
    else if (req.path() == "/hello")
    {
        resp->setStatusCode(HttpResponse::k200Ok);
        resp->setStatusMessage("OK");
        resp->setContentType("text/plain");
        resp->addHeader("Server", "Muduo");
        resp->setBody("hello, world!\n");
    }
    else
    {
        resp->setStatusCode(HttpResponse::k404NotFound);
        resp->setStatusMessage("Not Found");
        resp->setCloseConnection(true);
    }
}


HttpServer::HttpServer(EventLoop* pLoop, int threadnums)
    :_pLoop(pLoop)
    ,_pServer(pLoop)
    ,_timer(-1)
    ,_index(0)
    ,_threadnums(threadnums)
{
    _pServer.setCallback(this);
}

HttpServer::~HttpServer()
{}

void HttpServer::start()
{
    _pServer.start();
    _threadpool.start(_threadnums);
}

void HttpServer::onConnection(TcpConnection* pCon)
{
    pCon->setContext(HttpContext());      // TcpConnection 与一个 HttpContext（上下文对象） 绑定
}

void HttpServer::onMessage(TcpConnection* pCon, Buffer* pBuf, Timestamp receiveTime)
{
    HttpContext* context = boost::any_cast<HttpContext>(pCon->getMutableContext());
    if (!context->parseRequest(pBuf, receiveTime))   //使用context进行http包的解析
    {
        pCon->send("HTTP/1.1 400 Bad Request\r\n\r\n");
        cout<< "请求失败！"<<endl;
        pCon->shutdown();
    }

    if (context->gotAll())    //请求消息解析完毕，状态重置
    {
        Task task(this, pCon, context->request(), context);  
        _threadpool.addTask(task);
    }
}

void HttpServer::onWriteComplate(TcpConnection* pCon)
{
    cout << "onWriteComplate" << endl;
}

void HttpServer::onRequest(TcpConnection* pCon, HttpRequest& req)
{
    const string& connection = req.getHeader("Connection");      //取出头部
    bool close = connection == "close" ||
        (req.getVersion() == HttpRequest::kHttp10 && connection != "Keep-Alive");     //close 为true 或者 http1.0 为keep-alive
    HttpResponse response(close);
    dohttprequest(req, &response);
    Buffer buf;
    response.appendToBuffer(&buf);
    pCon->send(buf.getstring());
    if(response.closeConnection())
    {
        pCon->shutdown();
    }
}


//run in different therad
void HttpServer::run2(const string& str, void* tcp)
{
     
}

void HttpServer::run3(TcpConnection* pCon, HttpRequest req, HttpContext* context)
{

    onRequest(pCon, req);
    context->reset();         //本次请求完毕，重置 httpcontext 适用于长连接
}