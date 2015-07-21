#pragma once

#include <vector>

using namespace std;

template<typename T>
static void basicSelectionSort(vector<T>& t)
{
	for (int last = (t.size()-1); last >= 1; last--)
	{
		int largest = 0;
		
		for (int currIndex = 1; currIndex < last + 1; ++currIndex)
		{
			if (t.at(currIndex) > t.at(largest))
			{
				largest = currIndex;
			}
		}

		T temp = t.at(largest);
		t.at(largest) = t.at(last);
		t.at(last) = temp;
	}
}