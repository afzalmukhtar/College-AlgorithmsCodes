#include "session5_sort.h"

//Insertion Sort
//Sorts the array of Records on the serialnumber field using the Insertion Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int InsertionSort(Record* A, int n)
{
	long int i, count = 0;
	for(i = 1; i < n; i++)
	{
		Record temp = A[i];
		long int j = i - 1;
		while(j >= 0 && (++count) && A[j].serialnumber > temp.serialnumber)
		{
			A[j + 1] = A[j];
			--j;
		}	
		A[j + 1] = temp;
	}
	return count;
}

//Bubble Sort
//Sorts the array of Records on the serialnumber field using the Bubble Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int BubbleSort(Record* A, int n)
{
	long int count = 0, i, j;
	for(i = 0; i <= n - 2; i++)
		for(j = 0; j <= n - i - 2; j++)
		{
			if((++count) && A[j].serialnumber > A[j+1].serialnumber)
			{
				Record temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	return count;
}

//Selection Sort
//Sorts the array of Records on the serialnumber field using the Selection Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
long int SelectionSort(Record* A, int n)
{
	long int i, j, count = 0;
	for(i = 0; i < n - 1; i++)
	{
		int min = i;
		for(j = i + 1; j < n; j++)
			if((++count) && A[j].serialnumber < A[min].serialnumber)
				min = j;
		if(i != min)
		{
			Record temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
    return count;
}



//Merge sort will be for next lab sessions
//Merge Sort
//Sorts the array of Records on the serialnumber field using the Merge Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
//long int MergeSort(Record* A, int n);

// Quick sort will be for next lab sessions
//Quick Sort
//Sorts the array of Records on the serialnumber field using the Quick Sort algorithm.
//Sorts the array A in-place and returns the comparison count.
//long int QuickSort(Record* A, int n);
