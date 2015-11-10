#pragma once

#include <vector>

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

template<typename T>
void basicInsertionSort(vector<T>& t)
{	
	/*
	This sorting algorithm examines each element in the vector/array 
	to be sorted, and places it in the correct position in the array.

	This is the basic / naive implementation.

	Complexity / efficiency:
	Best case:		O(  n  )
	Worst case:		O(n ^ 2)
	Average case:	O(n ^ 2)
	*/

	for (auto i = 1; i < t.size(); ++i)
	{
		T nextItem = t.at(i);
		auto loc = i;

		//While (we aren't at the first element in the vector)
		//AND (the previous item is larger than the current item)
		while ( (loc > 0) && (t.at(loc - 1) > nextItem  ))
		{
			//Shift the item in loc-1 to the right
			t.at(loc) = t.at(loc - 1);
			loc--;
		}

		//Since everything (or nothing) got shifted, loc is where
		//next item should go.
		t.at(loc) = nextItem;
	}
}

template< typename ForwardIterator, typename Compare = std::less<typename std::iterator_traits<ForwardIterator>::value_type> >
void insertion_sort(ForwardIterator first, ForwardIterator last, Compare cmp = Compare())
{
	/*
	This sorting algorithm examines each element in the vector/array
	to be sorted, and places it in the correct position in the array.

	This implementation using standard library and iterators for 
	efficiency.

	This takes two forward iterators and a function to use to compare.

	Complexity / efficiency:
	Best case:		O( n )
	Worst case:		O( n^2 )
	Average case:	O( n^2 )
	*/

	//Iterate through the container
	for (auto it = first; it != last; ++it) {
		//Get the item to sort
		auto const insertion = std::upper_bound(first, it, *it, cmp);
		//Left rotation so that insertion is first
		std::rotate(insertion, it, std::next(it));
	}
}

template< typename ForwardIterator, typename Compare = std::less_equal<typename std::iterator_traits<ForwardIterator>::value_type> >
bool check_sorted(ForwardIterator first, ForwardIterator last, Compare cmp = Compare())
{
	/*
		This function checks through a container to see if it is sorted
		in ascending order.

		If sorted, it returns true; else returns false.

	*/

	//Iterate through each element in the container
	for (auto it = first; it != last; ++it)
	{
		//If the next item is not the last item...
		if (std::next(it) != last)
		{
			//...compare the current item to the next item
			//If this item is NOT smaller than the next item
			if (!cmp(*it, *std::next(it)))
			{
				//return false
				return false;
			}
			//else continue through the loop
		}
	}
	//Since we got through the whole container, every 
	//item is smaller than the next, so we are sorted.
	//Return true
	return true;

}

template<typename ForwardIterator, typename Compare = std::less<typename std::iterator_traits<ForwardIterator>::value_type> >
void merge_sort(ForwardIterator first, ForwardIterator last, Compare cmp = Compare())
{
	/*
		This is an iterator implementation of the merge sort algorithm.

		Merge sort breaks the container to be sorted into two parts,
		then recursively calls merge_sort on each new half, etc, etc.

		Each sorted section is then merged back in order to complete the 
		sorting of the container.
	
		Complexity / efficiency:
		Average case:	O( n * log(n) )
		Worst case:		O( n * log(n) )
	*/

	//First check the size of the container we are sorting
	auto const N = std::distance(first, last);

	//If the container only has one item, we're already done
	if (N < 2) return;

	//Find the mid point of the container
	auto middle = first + (N / 2);

	//Merge sort the left hand side
	merge_sort(first, middle, cmp);

	//Merge sort the right hand side
	merge_sort(middle, last, cmp);

	//Finally merge the sorted sections together again
	std::inplace_merge(first, middle, last, cmp);
}

template<typename ForwardIterator, typename Compare = std::less<typename std::iterator_traits<ForwardIterator>::value_type> >
void quick_sort(ForwardIterator first, ForwardIterator last, Compare cmp = Compare())
{
	/*
		This is an iterator implementation of the quick sort algorithm.

		This algorithm recursively sorts two smaller sorting problems in
		a container at either side of a pivot point.

		Quicksort partitions an array into items that are less than the 
		pivot and those that are greater than or equal to the pivot

		Complexity / efficiency:
		Average case:	O( n * log(n) )
		Worst case:		O( n^2 )
	*/

	//First check the container size:
	auto const N = std::distance(first, last);

	//If the container has only one item, we're already done
	if (N < 2) return;

	//Choose the midpoint as the pivot value
	auto middle = first + (N / 2);

	//Swap the middle to the front
	std::iter_swap(first, middle);
	
	//Sort the items about the pivot value using 
	//our compare function, cmp
	unsigned int i = 1;
	for (int j = 1; j < N; ++j)
	{
		if (cmp(*(first + j), *first))
		{
			std::iter_swap(first + j, first + i);
			++i;
		}
	}

	//Put the pivot back into position
	std::iter_swap(first, first + i - 1);

	//Sort each the array at each side of the pivot
	quicksort(first, first + i - 1,cmp);
	quicksort(first + i, last,cmp);

}