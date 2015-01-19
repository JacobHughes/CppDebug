/*=======================================================
	Code written by Jacob Hughes

	Copyright (C) Jacob Hughes 2015

	Contact for use:

	yacol@gmail.com
	https://github.com/JacobHughes/
=======================================================*/

#pragma once

#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

double __forceinline iteratorAverage(vector<double>::iterator &start, vector<double>::iterator &end)
{
	//Average data using iterators
	return std::accumulate(start, end, 0.0) / std::distance(start, end);
}

std::vector<double> simpleMovingAverage(vector<double> & data, int windowsize);