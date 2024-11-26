#pragma once
#include <string>
#include <WinSock2.h>
#include "define.h"

#pragma comment(lib, "ws2_32.lib")

struct FUser
{
	std::string UserIP;
	std::string UserPort;
	std::string UserName;
	sockaddr_in UserAddr;
	int connection = MAX_CONNECTION;
};