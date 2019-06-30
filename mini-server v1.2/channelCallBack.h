#pragma once

class channelCallBack
{
public:
	channelCallBack(){};
	~channelCallBack(){};

	virtual void Func(int sockfd) = 0;
	
};