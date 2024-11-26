#pragma once
#include <iostream>
#include <string>

std::string GetHead(std::string line)
{
	if (line.substr(0, 1) == "[")
	{
		size_t pos = line.find(']');
		return line.substr(1, pos - 1);
	}
	return "";
}

std::string GetBody(std::string line)
{
	if (GetHead(line) != "")
	{
		size_t pos = line.find(']');
		return line.substr(pos + 1);
	}
	return "";
}