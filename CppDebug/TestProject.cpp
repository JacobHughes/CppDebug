#pragma once

#include "TestProject.h"

using namespace std;

int main()
{
	Logger::instance().log(LoggerLevel_critical, "Does this project work?");

	vector<int> myVector;
	myVector.push_back(5);
	myVector.push_back(4);
	myVector.push_back(3);
	myVector.push_back(2);
	myVector.push_back(1);

	basicSelectionSort(myVector);

	for (int i = 0; i < myVector.size(); ++i)
	{
		Logger::instance() << to_string(myVector.at(i));
	}

	Logger::instance() << "Press the enter key to exit...";
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
	return 0;

}