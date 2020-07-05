#include <stdio.h>
#include <stdlib.h>
#include "horspool.h"
#include <string.h>

#define UNICODE_SIZE 256
/*
* Given the pattern fill the shift table used by Horspool's algorithm
* Table[pattern[i]] indicates the amount to be shifted when there is mismatch
* Initialize all the elements of Table with the length of the pattern
* The table size can be 256
*/

int *buildShiftTable(char *pattern)
{
	int len = strlen(pattern);
	int *Table = malloc(sizeof(int) * UNICODE_SIZE);
	for (int i = 0; i < UNICODE_SIZE; i++)
		Table[i] = len;
	
	// len - 1 because last character used for comparision so not included in calculating shift
	for(int i = 0; i < len - 1; i++)
		Table[(int) pattern[i]] = len - 1 - i;
		
	return Table;
}



/*
* Implement the horspool's string matching algoritm using the buildShiftTable()
  function to build the shift table.
* Compute offset of the first and last occurence of pattern in the text,
  In case of no occurrences of the pattern the value should be set to -1.
* Compute the number of occurences of the pattern in the text.
* Compute the number of characters compared while finding all occurences of the pattern in the given text
* Characters must be matched from left to right
*/

Result *horspoolStringMatch(char *pattern, char *text)
{
	Result *result = malloc(sizeof(Result));
	result -> firstOccurrence = -1;
	result -> lastOccurrence = -1;
	result -> charactersCompared = 0;
	result -> numOccurrences = 0;
	
	int len_p = strlen(pattern);
	int len_t = strlen(text);
	int *Table = buildShiftTable(pattern);
	
	int i = 0, j;
	
	while (i <= len_t - len_p)
	{
		j = len_p - 1;
		while (j >= 0 && pattern[j] == text[i + j])
		{
			j--;
			result -> charactersCompared++;
		}
		result -> charactersCompared++;
		
		if (j == -1)
		{
			if(result -> firstOccurrence == -1)
				result -> firstOccurrence = i;
				
			result -> lastOccurrence = i;
			result -> numOccurrences++;
		}
		
		i += Table[(int) text[i + j]];
	}
	return result;
}
