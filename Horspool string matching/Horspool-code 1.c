#include <stdio.h>
#include <stdlib.h>
#include "horspool.h"
#include <string.h>

/*
* Given the pattern fill the shift table used by Horspool's algorithm
* Table[pattern[i]] indicates the amount to be shifted when there is mismatch
* Initialize all the elements of Table with the length of the pattern
* The table size can be 256
*/

int *buildShiftTable(char *pattern)
{
	int len = strlen(pattern);
	int *Table = malloc(sizeof(int) * 256);
	for (int i = 0; i < 256; i++)
		Table[i] = len;

	for (int i = 0; i < len - 1; i++)
		Table[(int) pattern[i]] = len - i - 1;
	
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
	result->firstOccurrence = result->lastOccurrence = -1;
	result->charactersCompared = result->numOccurrences = 0;

	int pattern_len = strlen(pattern);
	int text_len = strlen(text);
	int *Table = buildShiftTable(pattern);
	int i, j;
	
	
	for (i = 0; i <= text_len - pattern_len; i += Table[(int) text[i + j]])
	{
		for (j = pattern_len - 1; pattern[j] == text[i + j]; j--);
		
		result->charactersCompared += pattern_len - 1- j;
		
		if(j == -1)
		{
			result->firstOccurrence = result->firstOccurrence == -1 ? i : result->firstOccurrence;
			result->lastOccurrence = i;
			result->numOccurrences++;
		}
		
	}
	return result;
}

