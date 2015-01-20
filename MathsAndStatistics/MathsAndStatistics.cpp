/*=======================================================
	Code written by Jacob Hughes

	Copyright (C) Jacob Hughes 2015

	Contact for use:

	yacol@gmail.com
	https://github.com/JacobHughes/
=======================================================*/

#include "MathsAndStatistics.h"

std::vector<double> simpleMovingAverage(vector<double> & data, int windowsize)
{
	/*==============================================================
		This Function smooths a vector of n elements using a moving
		average n elements wide (referred to here as the 
		windowsize).

		This function is fast as it relies on the degeneracy of the
		problem: in the middle of the vector (sufficiently far from 
		the ends) the calculation of the average can be computed:

		Smth_n = (data_n+w/2+1 + w*average(d_n-1) - d_n-w/2-1) / w

		With this degeneracy we can simply store the previous 
		calculated average and "slide" this along the vector to
		simplify calculation.

		The complex part is what to do at the end of the vector.

		The window size must be odd to compute this properly, but 
		the function accepts any integer input. If the input is 
		even, then it will decrement the windowsize by 1.
	==============================================================*/

	//You need an odd size window
	if (windowsize % 2 == 0)
	{
		--windowsize;
	}

	//double to store the previous averaged result
	double previous = 0.0;

	//integer division
	int halfWindow = windowsize / 2;
	int dataSize = static_cast<int>(data.size());

	//vector of new smoothed data
	vector<double> smooth_data(dataSize, NULL);

	//For loop to do the smoothing
	for (auto i = 0; i < dataSize; i++)
	{
		//First elemet is just ths same
		if (i == 0)
		{
			smooth_data.at(i) = data.at(i);
		}

		//Next the smoothing depends on how far we are along
		else if (i < (halfWindow))
		{
			vector<double>::iterator end = data.begin() + 2 * i + 1;
			smooth_data.at(i) = iteratorAverage(data.begin(), end);
		}

		//Standard general smoothing format
		else if ((i < dataSize - (halfWindow)))
		{
			if (previous)
			{
				smooth_data.at(i) = ((windowsize * previous) - data.at(i - 1 - halfWindow) + data.at(i + (halfWindow))) / windowsize;
				previous = smooth_data.at(i);
			}
			else
			{
				smooth_data.at(i) = iteratorAverage(data.begin() + i - (halfWindow), data.begin() + i + (halfWindow)+1);
				previous = smooth_data.at(i);
			}
		}

		//Approaching the end of the data set
		else if ((i < dataSize - 1))
		{
			vector<double>::iterator start = data.begin() + 1 + i - (dataSize - i);
			smooth_data.at(i) = iteratorAverage(start, data.end());
		}

		//Final element
		else
		{
			smooth_data.at(i) = data.at(i);
		}
	}

	//Return the smoothed vector
	return smooth_data;

}

//template<size_t rows, size_t cols>
bool isMagicSquare(std::vector< vector<int>> matrix)
{
	/*==============================================================
		This function takes an arbitrary size matrix and determines
		whether or not it is a magic square.

		The definition of a magic square can be found at:
		http://mathworld.wolfram.com/MagicSquare.html

	==============================================================*/

	/*==============================================================
		First the matric needs to actually be a square
	==============================================================*/

	int noOfRows = matrix.size();
	int noOfColumns = matrix.at(0).size();

	if (noOfColumns != noOfRows)
	{
		return false;
	}

	/*==============================================================
		Next sum each row and compare
	==============================================================*/
	int currentSum = 0;

	//Get first row sum
	for (int j = 0; j < noOfRows; ++j)
	{
		currentSum += matrix.at(0).at(j);
	}

	int previousValue = currentSum;
	currentSum = 0;

	for (auto i = 1; i < noOfColumns; ++i)
	{
		//Loop over each item in this and sum
		for (auto j = 0; j < noOfRows; ++j)
		{
			currentSum += matrix.at(i).at(j);
		}

		if (previousValue != currentSum)
		{
			return false;
		}

		currentSum = 0;
	}


	/*==============================================================
		Next sum over each column and compare
	==============================================================*/
	for (auto j = 0; j < noOfRows; ++j)
	{
		//Loop over each item in this and sum
		for (auto i = 0; i < noOfColumns; ++i)
		{
			currentSum += matrix.at(i).at(j);
		}

		if (previousValue != currentSum)
		{
			return false;
		}

		currentSum = 0;
	}

	
	/*==============================================================
		Now sum top-left to bottom-right diagonal and compare
	==============================================================*/
	for (auto i = 0; i < noOfRows; ++i)
	{
		currentSum += matrix.at(i).at(i);
	}

	if (previousValue != currentSum)
	{
		return false;
	}

	currentSum = 0;
	

	/*==============================================================
		Now sum bottom-left to top-right diagonal and compare
	==============================================================*/
	int i = matrix.size() - 1;
	for (auto j = 0; j < noOfColumns; ++j)
	{
		currentSum += matrix.at(i).at(j);
		--i;
	}
	
	if (previousValue != currentSum)
	{
		return false;
	}

	/*==============================================================
		Finally, we have a magic Square!
	==============================================================*/
	return true;
}