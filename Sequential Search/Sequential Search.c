#include <stdio.h>
#include "ss.h"

//Find the offset of the first occurrence of the key in an array of integers
//Return -1 in case of no occurrences of the key.
int searchFirstOccurrence(int arr[], int n, int key)
{
	int i;
	for(i = 0; i < n; i++)
		if(arr[i] == key)
			return i;
	return -1;
}

//Find the offset of the last occurrence of the key in an array of integers
//Return -1 in case of no occurrences of the key.
int searchLastOccurrence(int arr[], int n, int key)
{
	int i, lindex = -1;
	for(i = 0; i < n; i++)
		if(arr[i] == key)
			lindex = i;
	return lindex;
}

//Find the number of occurrences of the key in an array of integers
int numOccurrences(int arr[], int n, int key)
{
	int i, count = 0;
	for(i = 0; i < n; i++)
		if(arr[i] == key)
			count++;
	return count;
}
