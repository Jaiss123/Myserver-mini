
#include "Buffer.h"

Buffer::Buffer()
{}

Buffer::~Buffer()
{}

//string转换为char*
const char* Buffer::peek()
{
    return _buf.c_str();
}

//当前buf大小
int Buffer::readableBytes()
{
    return static_cast<int>(_buf.size());    
}

//取len-size()
void Buffer::retrieve(int len)
{
    _buf = _buf.substr(len, _buf.size());   
}

void Buffer::append(const string& data)
{
    _buf.append(data);
}

string Buffer::retrieveAllAsString()
{
    return retrieveAsString(readableBytes());
}

string Buffer::retrieveAsString(size_t len)
{
    string result(peek(), len);
    retrieve(len);
    return result;
}
