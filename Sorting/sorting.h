#pragma once

#include <vector>

using namespace std;

template<typename T>
static void basicSelectionSort(vector<T>& t)
{
	/*
		This is a basic (perhaps naive) implementation of a 
		selection sort algorithm, in it's most basic form.

		We evaluate run through each item in the vector, and 
		swap it with the largest value in the rest of the 
		vector.

		Complexity/efficiency:
		Best case:		O( n^2 )
		Worst case:		O( n^2 )
		Average case:	O( n^2 )
	
	*/
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

		//Perform the swap here
		T temp = t.at(largest);
		t.at(largest) = t.at(last);
		t.at(last) = temp;
	}
}

template< typename ForwardIterator, typename Compare = std::less<typename std::iterator_traits<ForwardIterator>::value_type> >
void selection_sort(ForwardIterator first, ForwardIterator last, Compare cmp = Compare())
{
	/*
		This is more specialised C++ implementation of the selection sort
		which makes use of iterators and std operations, which should be 
		more optimised.

		This implementation allows user specified comparison function, 
		so non-default or primitive objects can be sorted as required.
		The default comparison is operator<

		Complexity/efficiency:
		Best case:		O( n^2 )
		Worst case:		O( n^2 )
		Average case:	O( n^2 )
	*/

	for (auto i = first; i != last; ++i) {
		//Find the smallest element
		auto const selection = std::min_element(i, last, cmp);
		//Swap elements
		std::iter_swap(selection, i);
	}
}