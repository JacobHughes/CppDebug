#pragma once

#include "TestProject.h"

using namespace std;

void testSelectionSort(void)
{
	Logger::instance().log(LoggerLevel_normal, "Now testing selection sort");
	
	srand((unsigned)time(NULL));
	
	vector<int> myVector(10000, 1);
	for (auto i = 0; i < myVector.size(); ++i)
	{
		myVector.at(i) = rand() % 10000 + 1; //random number in the range 1 - 10000
	}

	string myVectorStr;
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector.at(i));
		myVectorStr += " ";
	}

	vector<int> myVectorOriginal = myVector;
	vector<int> myVector2 = myVector;

	Logger::instance().log(LoggerLevel_normal, "Before sorting myVector is: " + myVectorStr);

	clock_t start;
	start = std::clock();
	basicSelectionSort(myVector);
	double basicTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector.at(i));
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "After basicSelectionSort myVector is: " + myVectorStr);
	Logger::instance().log(LoggerLevel_normal, "This took " + to_string(basicTime) + "s.");

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector2.at(i));
		myVectorStr += " ";
	}
	Logger::instance().log(LoggerLevel_normal, "Before sorting myVector2 is (same as myVector): " + myVectorStr);

	start = std::clock();
	selection_sort(myVector2.begin(), myVector2.end());
	double iterTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector2.at(i));
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "After selection_sort myVector2 is: " + myVectorStr);
	Logger::instance().log(LoggerLevel_normal, "This took " + to_string(iterTime) + "s.");
}

void testInsertionSort(void)
{
	Logger::instance().log(LoggerLevel_normal, "Now testing insertion sort");

	srand((unsigned)time(NULL));

	vector<int> myVector(10000, 1);
	for (auto i = 0; i < myVector.size(); ++i)
	{
		myVector.at(i) = rand() % 10000 + 1; //random number in the range 1 - 10000
	}

	string myVectorStr;
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector.at(i));
		myVectorStr += " ";
	}

	vector<int> myVectorOriginal = myVector;
	vector<int> myVector2 = myVector;

	Logger::instance().log(LoggerLevel_normal, "Before sorting myVector is: " + myVectorStr);

	clock_t start;
	start = std::clock();
	basicInsertionSort(myVector);
	double basicTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector.at(i));
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "After basicInsertionSort myVector is: " + myVectorStr);
	Logger::instance().log(LoggerLevel_normal, "This took " + to_string(basicTime) + "s.");

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector2.at(i));
		myVectorStr += " ";
	}
	Logger::instance().log(LoggerLevel_normal, "Before sorting myVector2 is (same as myVector): " + myVectorStr);

	start = std::clock();
	insertion_sort(myVector2.begin(), myVector2.end());
	double iterTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector2.at(i));
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "After insertion_sort myVector2 is: " + myVectorStr);
	Logger::instance().log(LoggerLevel_normal, "This took " + to_string(iterTime) + "s.");
}

int main()
{
	Logger::instance().log(LoggerLevel_critical, "Does this project work? Let's see...");

	testSelectionSort();

	testInsertionSort();



	Logger::instance() << "Press the enter key to exit...";
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
	return 0;

}