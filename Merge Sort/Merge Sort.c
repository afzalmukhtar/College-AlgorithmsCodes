#include <stdio.h>
#include "mergeSort.h"
// Merges two sorted halfs of an array into a single sorted array
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
	int left_len = mid - start + 1;
	int right_len = end - mid;
	int left_Half[left_len], right_Half[right_len];
	int i, j, k;
	
	for(i = 0; i < left_len; i++)
		left_Half[i] = a[start + i];
	
	for(i = 0; i < right_len; i++)
		right_Half[i] = a[mid + i + 1];
		
	i = 0; j = 0; k = start;
	
	while(i < left_len && j < right_len)
	{
		if(left_Half[i] < right_Half[j])
			a[k++] = left_Half[i++];
		else
			a[k++] = right_Half[j++];
	}
	
	while(i < left_len)
		a[k++] = left_Half[i++];
	
	while(j < right_len)
		a[k++] = right_Half[j++];
}

// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		mergeSortedHalfs(a, start, mid, end);
	}
}

// Implement insertion sort
// n - number of elements in the array
void insertionSort(int *a, int start, int end)
{
	int n = end - start;
	for(int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			--j;
		}	
		a[j + 1] = temp;
	}
	
}

// Implement a function which applies merge sort only if
// size of the array is larger than that of parameter
// if not apply insertion sort.
// Use mergeSortedHalfs() and insertionSort() declared above to do the same.
void selectiveMergeSort(int *a, int start, int end, int parameter)
{
	if((end - start) < parameter)
		insertionSort(a, start, end);
	else
		mergeSort(a, start, end);
}
