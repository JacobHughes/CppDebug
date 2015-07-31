#pragma once

#include "TestProject.h"

using namespace std;

void testRectangle()
{
	Logger::instance().log(LoggerLevel_normal, "Testing a rectangle");

	Rectangle myR(2.5, 4.5);

	Logger::instance().log(LoggerLevel_normal, "The area of this rectangle is: " + to_string(myR.getArea()));

	Rectangle myR2(5.0, 5.0);

	Logger::instance().log(LoggerLevel_normal, "The area of the second rectangle is: " + to_string(myR.getArea()));

	bool bigger = myR > myR2;

	bool smaller = myR < myR2;

	Logger::instance().log(LoggerLevel_normal, "Is R1 bigger than R2? " + to_string(bigger));

	Logger::instance().log(LoggerLevel_normal, "Is R1 smaller than R2? " + to_string(smaller));
	

}

void sortRectangles()
{
	Logger::instance().log(LoggerLevel_normal, "Now testing sorting rectangle objects");

	srand((unsigned)time(NULL));

	vector<Rectangle> myRectangles;

	for (auto i = 0; i < 10000; ++i)
	{
		Rectangle r(rand() % 10 + 1, rand() % 10 + 1);
		myRectangles.push_back(r);
	}

	vector<Rectangle>myRectangles2 = myRectangles;
	vector<Rectangle>myRectangles3 = myRectangles;

	//Logger::instance().log(LoggerLevel_normal, to_string(myRectangles.at(0).getArea()));

	selection_sort(myRectangles.begin(),myRectangles.end());

	//Logger::instance().log(LoggerLevel_normal,to_string(check_sorted(myRectangles.begin(), myRectangles.end())));

	insertion_sort(myRectangles2.begin(), myRectangles2.end());
}

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

	Logger::instance().log(LoggerLevel_normal, to_string(check_sorted(myVector2.begin(), myVector2.end())));
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

void testMergeSort(void)
{
	Logger::instance().log(LoggerLevel_normal, "Now testing merge sort");

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
	merge_sort(myVector.begin(), myVector.end());
	double basicTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myVector.at(i));
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "After merge_sort myVector is: " + myVectorStr);
	Logger::instance().log(LoggerLevel_normal, "This took " + to_string(basicTime) + "s.");

	Logger::instance().log(LoggerLevel_normal, "Now testing sorting rectangle objects");
	
	vector<Rectangle> myRectangles;

	for (auto i = 0; i < 10000; ++i)
	{
		Rectangle r((rand() % 100) + 1, (rand() % 100) + 1);
		myRectangles.push_back(r);
	}

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myRectangles.at(i).getArea());
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "Before sorting myRectangles is: " + myVectorStr);

	vector<Rectangle>myRectangles2 = myRectangles;
	vector<Rectangle>myRectangles3 = myRectangles;

	//Logger::instance().log(LoggerLevel_normal, to_string(myRectangles.at(0).getArea()));

	start = std::clock();
	merge_sort(myRectangles.begin(), myRectangles.end());
	basicTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myRectangles.at(i).getArea());
		myVectorStr += " ";
	}
	Logger::instance().log(LoggerLevel_normal, "After merge_sort myRectangles is: " + myVectorStr);

	Logger::instance().log(LoggerLevel_normal, "This took " + to_string(basicTime) + "s.");
}

int main()
{
	Logger::instance().log(LoggerLevel_critical, "Does this project work? Let's see...");

	//testRectangle();

	//sortRectangles();

	//testSelectionSort();

	//testInsertionSort();

	testMergeSort();


	Logger::instance() << "Press the enter key to exit...";
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
	return 0;

}