#include "ServerMain.h"

void MainFunc::InitMain()
{
	while (1)
	{
		if (Var::Server.initServer(DEFAULT_PORT + Var::PortAdd) == 0)
		{
			break;
		}
		Var::PortAdd++;
	}
}

void MainFunc::LaunchThread()
{
	std::thread th_RecvMessage(ThreadFunc::RecvMessage);
	th_RecvMessage.detach();
}

void MainFunc::BlockMain()
{
	while (1)
	{
		Sleep(60000);
	}
}

void ThreadFunc::RecvMessage()
{
	FRecvBuffer loc_buffer;
	FUser loc_user;
	while (1)
	{
		loc_buffer = Var::Server.recvString();
		if (loc_buffer.success)
		{
			loc_user.UserIP = inet_ntoa(loc_buffer.sockaddr.sin_addr);
			loc_user.UserPort = std::to_string(ntohs(loc_buffer.sockaddr.sin_port));
			loc_user.UserAddr = loc_buffer.sockaddr;
		}
	}
}

void CommandFunc::InitFunctionMap()
{
	Var::FunctionMap["PRINT"] = &Print;
}

void CommandFunc::CallCommandByName(std::string name, FUser from, std::string head, std::string body)
{
	if (Var::FunctionMap.find(name) != Var::FunctionMap.end()) {
		Var::FunctionMap[name](from, head, body);
	}
}

void CommandFunc::Print(FUser from, std::string head, std::string body)
{

}

int main(int argc, char argv[])
{
	MainFunc::InitMain();
	MainFunc::LaunchThread();
	MainFunc::BlockMain();
	return 0;
}


