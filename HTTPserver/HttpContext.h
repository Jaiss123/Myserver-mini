

#ifndef MUDUO_NET_HTTP_HTTPCONTEXT_H
#define MUDUO_NET_HTTP_HTTPCONTEXT_H

#include "HttpRequest.h"


class Buffer;

class HttpContext
{
 public:
  enum HttpRequestParseState
  {
    kExpectRequestLine,           //解析 请求行 状态
    kExpectHeaders,               //解析 请求头 状态
    kExpectBody,                  //解析 实体 状态
    kGotAll,                      
  };

  HttpContext()
    : state_(kExpectRequestLine)
  {
  }

  // default copy-ctor, dtor and assignment are fine

  // return false if any error
  bool parseRequest(Buffer* buf, Timestamp receiveTime);

  bool gotAll() const
  { return state_ == kGotAll; }

  //重置状态
  void reset()
  {
    state_ = kExpectRequestLine;
    HttpRequest dummy;
    request_.swap(dummy);
  }

  const HttpRequest& request() const
  { return request_; }

  HttpRequest& request()
  { return request_; }

 private:
  bool processRequestLine(const char* begin, const char* end);

  HttpRequestParseState state_;         //请求解析状态
  HttpRequest request_;                 //http请求
};

#endif  // MUDUO_NET_HTTP_HTTPCONTEXT_H
