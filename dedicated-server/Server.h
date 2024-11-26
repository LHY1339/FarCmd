#pragma once
#include <RecvBuffer.h>
#include <WinSock2.h>
#include <iostream>

#pragma warning(disable:4996)
#pragma warning(disable:4267)
#pragma comment(lib, "ws2_32.lib")

class CServer
{
private:
    WSADATA __wsadata;
    SOCKET __udpsocket;
    sockaddr_in __serveraddr;
    char __buffer[1024];
public:
    int initServer(int ADDR_PORT);
    int sendString(std::string Message, sockaddr_in clientAddr);
    FRecvBuffer recvString();
};

