#pragma once

#include "TestProject.h"

using namespace std;

void testRectangle()
{
	Logger::instance().log(LoggerLevel_normal, "Testing a rectangle");

	MyRectangle myR(2.5, 4.5);

	Logger::instance().log(LoggerLevel_normal, "The area of this rectangle is: " + to_string(myR.getArea()));

	MyRectangle myR2(5.0, 5.0);

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

	vector<MyRectangle> myRectangles;

	for (auto i = 0; i < 10000; ++i)
	{
		MyRectangle r(rand() % 10 + 1, rand() % 10 + 1);
		myRectangles.push_back(r);
	}

	vector<MyRectangle>myRectangles2 = myRectangles;
	vector<MyRectangle>myRectangles3 = myRectangles;

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
	
	vector<MyRectangle> myRectangles;

	for (auto i = 0; i < 10000; ++i)
	{
		MyRectangle r((rand() % 100) + 1, (rand() % 100) + 1);
		myRectangles.push_back(r);
	}

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myRectangles.at(i).getArea());
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "Before sorting myRectangles is: " + myVectorStr);

	vector<MyRectangle>myRectangles2 = myRectangles;
	vector<MyRectangle>myRectangles3 = myRectangles;

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

void testQuickSort()
{
	Logger::instance().log(LoggerLevel_normal, "Now testing quick sort");

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
	quick_sort(myVector.begin(), myVector.end());
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

	vector<MyRectangle> myRectangles;

	for (auto i = 0; i < 10000; ++i)
	{
		MyRectangle r((rand() % 100) + 1, (rand() % 100) + 1);
		myRectangles.push_back(r);
	}

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myRectangles.at(i).getArea());
		myVectorStr += " ";
	}

	Logger::instance().log(LoggerLevel_normal, "Before sorting myRectangles is: " + myVectorStr);

	vector<MyRectangle>myRectangles2 = myRectangles;
	vector<MyRectangle>myRectangles3 = myRectangles;

	//Logger::instance().log(LoggerLevel_normal, to_string(myRectangles.at(0).getArea()));

	start = std::clock();
	quick_sort(myRectangles.begin(), myRectangles.end());
	basicTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	myVectorStr = "";
	for (auto i = 0; i < 11; ++i)
	{
		myVectorStr += to_string(myRectangles.at(i).getArea());
		myVectorStr += " ";
	}
	Logger::instance().log(LoggerLevel_normal, "After merge_sort myRectangles is: " + myVectorStr);
	//Logger::instance().log(LoggerLevel_normal, to_string(check_sorted(myRectangles.begin(), myRectangles.end())));
	Logger::instance().log(LoggerLevel_normal, "This took " + to_string(basicTime) + "s.");
}

void testVectorAllocation()
{
	int reps = 100;
	vector<double> unallocated;
	vector<double> preallocated;
	preallocated.reserve(reps);

	clock_t start = std::clock();
	
	for (auto i = 0; i < reps; ++i)
	{
		unallocated.push_back(10);
	}
	double unallocatedTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	Logger::instance().log(LoggerLevel_normal, "Time for unallocated vector of " + to_string(reps) + ": " + to_string(unallocatedTime));

	start = std::clock();

	for (auto i = 0; i < reps; ++i)
	{
		preallocated.push_back(10);
	}
	double preallocatedTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	Logger::instance().log(LoggerLevel_normal, "Time for preallocated vector of " + to_string(reps) + ": " + to_string(preallocatedTime));
}

void testArrayAllocation()
{
	const int reps = 100;// std::numeric_limits<int>::max();
	const int bigReps = 100;
	double testArray[reps];
	double * testArrayPtr = new double[bigReps];

	clock_t start = std::clock();

	for (auto i = 0; i < reps; ++i)
	{
		testArray[i] =10;
	}

	double arrayTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	Logger::instance().log(LoggerLevel_normal, "Time for stack preallocatd array of " + to_string(reps) + ": " + to_string(arrayTime));

	start = std::clock();

	for (auto i = 0; i < reps; ++i)
	{
		testArrayPtr[i] = 10;
	}

	double bigArrayTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	Logger::instance().log(LoggerLevel_normal, "Time for heap preallocatd array of " + to_string(bigReps) + ": " + to_string(bigArrayTime));

	delete[] testArrayPtr;

}

void compareAccumulate()
{
	int reps = 100;
	vector<double> accManual(reps, 1);
	vector<double> accBuiltIn(reps, 1);

	double resultManual = 0.0;
	double resultBuiltIn = 0.0;
	
	clock_t start = std::clock();

	for (int i = 0; i < reps; ++i)
	{
		resultManual += accManual.at(i);
	}
	double manualTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	Logger::instance().log(LoggerLevel_normal, "Time to sum vector manually with " + to_string(reps) + " items: " + to_string(manualTime));

	start = std::clock();

	resultBuiltIn = std::accumulate(accBuiltIn.begin(), accBuiltIn.end(), 0.0);
	
	double builtInTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	Logger::instance().log(LoggerLevel_normal, "Time to sum vector using builtin with " + to_string(reps) + " items: " + to_string(builtInTime));

}

int main()
{
	setUpDebugEnvironment();

	Logger::instance().log(LoggerLevel_critical, "Does this project work? Let's see...");

	//Logger::instance().setMode(LoggerMode_silent);

	//Logger::instance().log(LoggerLevel_normal, to_string(Logger::instance().getMode()));

	//testRectangle();

	//sortRectangles();

	//testSelectionSort();

	//testInsertionSort();

	//testMergeSort();

	//testQuickSort();

	testVectorAllocation();

	testArrayAllocation();

	compareAccumulate();

	Logger::instance().log(LoggerLevel_critical, "Oh my god!");

	Logger::instance() << "Press the enter key to exit...";
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
	return 0;

}