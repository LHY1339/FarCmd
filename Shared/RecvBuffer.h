#pragma once
#include <WinSock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

struct FRecvBuffer
{
	std::string message;
	sockaddr_in sockaddr;
	bool success = false;
};