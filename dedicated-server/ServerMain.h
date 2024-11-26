#pragma once
#include "Server.h"
#include <User.h>
#include <RecvBuffer.h>
#include <thread>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Var
{
	CServer Server;
	int PortAdd = 0;
	std::vector<FUser> UserList;
	std::vector<FUser> ControllerList;
	std::unordered_map<std::string, std::function<void(FUser, std::string, std::string)>> FunctionMap;
}

namespace ThreadFunc
{
	void RecvMessage();
}

namespace CommandFunc
{
	void InitFunctionMap();
	void CallCommandByName(std::string name, FUser from, std::string head, std::string body);
	void Print(FUser from, std::string head, std::string body);
}

namespace MainFunc
{
	void InitMain();
	void LaunchThread();
	void BlockMain();
}

int main(int argc, char argv[]);