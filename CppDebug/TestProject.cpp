#pragma once

#include "TestProject.h"

using namespace std;

void testSelectionSort(void)
{
	Logger::instance().log(LoggerLevel_normal, "Now testing selection sort");
	vector<int> myVector;
	myVector.push_back(10);
	myVector.push_back(9);
	myVector.push_back(8);
	myVector.push_back(7);
	myVector.push_back(6);
	myVector.push_back(5);
	myVector.push_back(4);
	myVector.push_back(3);
	myVector.push_back(2);
	myVector.push_back(1);

	string myVectorStr;
	for (auto i = 0; i < myVector.size(); ++i)
	{
		myVectorStr += to_string(myVector.at(i));
		myVectorStr += " ";
	}

	vector<int> myVectorOriginal = myVector;
	vector<int> myVector2 = myVector;

	Logger::instance().log(LoggerLevel_normal, "Before sorting myVector is: " + myVectorStr);

	basicSelectionSort(myVector);

	myVectorStr = "";
	for (auto i = 0; i < myVector.size(); ++i)
	{
		myVectorStr += to_string(myVector.at(i));
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "After basicSelectionSort myVector is: " + myVectorStr);

	vector<int>::iterator f = myVector2.begin();
	vector<int>::iterator l = myVector2.end();

	selection_sort(f, l);

	myVectorStr = "";
	for (auto i = 0; i < myVector2.size(); ++i)
	{
		myVectorStr += to_string(myVector2.at(i));
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "After selection_sort myVector is: " + myVectorStr);
}

int main()
{
	Logger::instance().log(LoggerLevel_critical, "Does this project work? Let's see...");

	testSelectionSort();

	Logger::instance() << "Press the enter key to exit...";
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
	return 0;

}