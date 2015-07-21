#pragma once

#include "TestProject.h"

using namespace std;

int main()
{
	Logger::instance().log(LoggerLevel_critical, "Does this project work?");

	Logger::instance() << "Press the enter key to exit...";
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
	return 0;

}