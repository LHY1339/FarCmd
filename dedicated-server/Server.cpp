#include "Server.h"

int CServer::initServer(int ADDR_PORT)
{
    if (WSAStartup(MAKEWORD(2, 2), &__wsadata) != 0) {
        return -1;
    }

    __udpsocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (__udpsocket == INVALID_SOCKET) {
        WSACleanup();
        return -1;
    }

    __serveraddr.sin_family = AF_INET;
    __serveraddr.sin_addr.s_addr = INADDR_ANY;
    __serveraddr.sin_port = htons(ADDR_PORT);

    if (bind(__udpsocket, (sockaddr*)&__serveraddr, sizeof(__serveraddr)) == SOCKET_ERROR) {
        closesocket(__udpsocket);
        WSACleanup();
        return -1;
    }

    std::cout << "server launch as port " << ADDR_PORT << std::endl;
    return 0;
}

int CServer::sendString(std::string Message, sockaddr_in clientAddr)
{
    int loc_clientAddrSize = sizeof(clientAddr);
    int loc_sendResult = sendto(__udpsocket, Message.c_str(), strlen(Message.c_str()), 0, (sockaddr*)&clientAddr, loc_clientAddrSize);
    return loc_sendResult;
}

FRecvBuffer CServer::recvString()
{
    sockaddr_in loc_recvaddr;
    FRecvBuffer loc_result;
    int loc_recvAddrSize = sizeof(loc_recvaddr);
    int bytesReceived = recvfrom(__udpsocket, __buffer, sizeof(__buffer), 0, (sockaddr*)&loc_recvaddr, &loc_recvAddrSize);
    if (bytesReceived != SOCKET_ERROR) {
        __buffer[bytesReceived] = '\0';
        loc_result.sockaddr = loc_recvaddr;
        loc_result.message = __buffer;
        loc_result.success = true;
    }
    return loc_result;
}
