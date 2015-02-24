/*=======================================================
	Code written by Jacob Hughes

	Copyright (C) Jacob Hughes 2015

	Contact for use:

	yacolt@gmail.com
	https://github.com/JacobHughes/
=======================================================*/

#pragma once

#include <vector>
#include <iterator>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

/*=======================================================
	Histogram struture for returning bin Edges and bin
	counts for a histogram.
=======================================================*/
struct struct_Histogram
{
	std::vector<double> binEdges;
	std::vector<double> binCounts;
};


/*=======================================================
	For use in the simpleMovingAverage() function,
	this returns the average based on a sub-section of
	a vector, determined by the start and end 
	parameters.
=======================================================*/
double __forceinline iteratorAverage(vector<double>::iterator &start,vector<double>::iterator &end)
{
	//Average data using iterators
	return std::accumulate(start, end, 0.0) / std::distance(start, end);
}

/*=======================================================
	The simple moving average smooths data by calculating
	the average value within a window, then moving this
	window over all elements in the vector.
=======================================================*/
std::vector<double> simpleMovingAverage(std::vector<double> & data, int windowsize);

/*=======================================================
	This function takes an arbitrary size matrix and 
	determines	whether or not it is a magic square.
	This does not check for unique numbers in each 
	location of	the matrix --> this is to do later.
=======================================================*/
bool isMagicSquare(std::vector< vector<int>> matrix);

/*=======================================================
	This function bins data into a histogram, with bins
	over the range of data.
	It returns a histogram structure (defined above).
=======================================================*/
struct_Histogram histogram(vector<double> data, double binWidth);

/*=======================================================
	This function bins data into a histogram, with bins
	determined by user input.
	It returns a histogram structure (defined above).
=======================================================*/
struct_Histogram histogram(vector<double> data, double binWidth, double binStart, double binStop);

/*=======================================================
	Calculate the population standard deviation of a 
	vector.
=======================================================*/
template <typename	T>
T populationStandardDeviation(vector<T> &data)
{
	//Get the mean of the data
	auto mean = meanAverage(data);

	//Calculate sum of (data - mean)^2
	T a = T();
	for (const auto val : data)
	{
		a += (val - mean) * (val - mean);
	}

	//return (1/n) * sqrt(a) 
	return std::sqrt(a / data.size());
}

/*=======================================================
	Calculate the sample standard deviation of a 
	vector.
=======================================================*/
template <typename	T>
T sampleStandardDeviation(vector<T> &data)
{
	//Get the mean of the data
	auto mean = meanAverage(data);

	//Calculate sum of (data - mean)^2
	T a = T();
	for (const auto val : data)
	{
		a += (val - mean) * (val - mean);
	}

	//return (1/(n-1)) * sqrt(a)
	return std::sqrt(a / (data.size()-1));
}

/*=======================================================
	Calculate the mean of a whole vector
=======================================================*/
template <typename T>
__forceinline T meanAverage(vector<T> &data)
{
	auto sum = std::accumulate(data.begin(), data.end(), T());
	return sum / data.size();
}