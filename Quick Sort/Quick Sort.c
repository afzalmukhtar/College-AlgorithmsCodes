#include "quickSort.h"


/**
 * Structure containing two pointers to int arrays

typedef struct
{
    int *first, *second;
    int firstLen, secondLen;
} ptrPair;
*/
/**
 * divide(): 
 * Partition (rearrange) the array A[0..n-1]
 * into two (possibly empty) sub-arrays A[0 to q-1] and A[q+1 to n-1]
 * such that each element of A[0 to q-1] is less than or equal to A[q], 
 * which is, in turn, less than or equal to each element of A[q+1 to n-1].
 * Index q should be decided by calling the partition function
 * Return the two new pointers (along with length) by assigning them to a ptrPair structure
 */
ptrPair divide(int *a, int n)
{
	ptrPair pair;
	int q = getPartitionIndex(a, n) + 1;
	
	pair.first = a;
	pair.firstLen = q;
	
	pair.second = a + q;
	pair.secondLen = n - q;
	return pair;
}

/**
 * getPartitionIndex():
 * Choose the first element from the array A[0..n-1] as the pivot element
 * Partition the array using hoare's partitioning scheme, 
 * and return the index of the split
 * HOARE-PARTITION(A, p, r)
    x = A[p]
    i = p - 1
    j = r + 1
    while true
        repeat
            j = j - 1
        until A[j] ≤ x
        repeat
            i = i + 1
        until A[i] ≥ x
        if i < j
            exchange A[i] with A[j]
        else return j
 */
int getPartitionIndex(int *a, int n)
{
	int pivot = a[0];
	int i = -1, j = n;
	while(1)
	{
		do{ i++; }while(a[i] < pivot);
		do{ j--; }while(a[j] > pivot);
		
		if(i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else 
			return j;
	}
}

/**
 * conquer():
 * Call the divide function to divide the array,
 * and then conquer the two sub arrays recursively
 */
void conquer(int *a, int n)
{
	ptrPair pair;
	if(!isSorted(a, n))
	{
		pair = divide(a, n);
		conquer(pair.first, pair.firstLen);
		conquer(pair.second, pair.secondLen);
	}
}

// Wrapper function to call conquer() for the first time.
void quickSort(int *a, int n)
{
	conquer(a, n);
}

// Check if an array is sorted.
// Return 1 if the array is sorted, 0 otherwise.
int isSorted(int *a, int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				return 0;
	return 1;
}
