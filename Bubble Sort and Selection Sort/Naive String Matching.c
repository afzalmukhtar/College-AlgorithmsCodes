#include <stdio.h>
#include <stdlib.h>


int k, swaps;
// Check if an array is sorted.
// Return 1 if the array is sorted, 0 otherwise.
int isSorted(int *a, int n)
{
	int i;
	for(i = 0; i < n - 1; i++)
		if(a[i] > a[i + 1])
			return 0;
	return 1;
}

//Consider an array a[0] to a[n-1]. 
//For each element a[i], which is greater than or equal to all the
//elements from a[0] thru a[i-1], move a[i] to a[k] where all the elements from
//a[i+1] thru a[k] are less than a[i] and either k=n-1 or a[k+1] >= a[i].
//Essentially, one pass of bubbling larger elements from left to right.
//Eg: Array 1 4 3 2 6 5 is transformed to 1 3 2 4 5 6.
void bubblePass(int *a, int n)
{
	int i;
	for(k = 0; k < n; k++)
	{
		if(isSorted(a, n))
			return;
		for(i = 0; i < n - k - 1; i++)
			if(a[i] > a[i+1])
			{
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
	}
}

//Implement Bubble sort using bubblePass() declared above.
void bubbleSort(int *a, int n)
{
	if(isSorted(a, n))
		k = 0;
	else
		bubblePass(a, n);
}

//Find the minimum number of BubblePasses required to sort by Bubble sort
//algorithm. Note that a sorted array does not require any bubblePasses. 
//Use isSorted() function before calling BubblePass().
int numBubblePasses(int *a, int n)
{
	bubbleSort(a, n);
	return k;
}

//Find the offset (that is, index) of the maximum element in an array.
//In case of multiple occurrences of the maximum element,
// return the largest offset (that is, rightmost index).
int maxIndex(int *a, int n)
{
	int maxIndex = n, i;
	for(i = 0; i <= n; i++)
		if(a[i] >= a[maxIndex])
			maxIndex = i;
	return maxIndex;
}

//Consider an array a[0] to a[n-1].
//Let i be the largest offset of the maximum element in the array.
//Swap a[i] with a[n-1] only if i < n-1.
//Use maxIndex() declared above.
void swapWithMax(int *a, int n)
{
	int max = maxIndex(a, n);
	if(max < n)
	{
		++swaps;
		int temp = a[n];
		a[n] = a[max];
		a[max] = temp;
	}
	return;
}

//Implement Selection sort using maxIndex() and swapWithMax() declared above.
void selectionSort(int *a, int n)
{
	swaps = 0;
	for(; n >= 0; n--)
		swapWithMax(a, n);
	return;
}

//Find the number of swaps in selectionSort() declared above.
int numSwaps(int *a, int n)
{
	selectionSort(a, --n);
	return swaps;
}
