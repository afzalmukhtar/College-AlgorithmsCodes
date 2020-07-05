#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find the offset of the first occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchFirstOccurrence(char *pattern, char *text)
{
	int i, j;
	for(i = 0; i < strlen(text) - strlen(pattern); i++)
	{
		for(j = 0; (pattern[j] != '\0') && (pattern[j] == text[i + j]); j++);
		if(strlen(pattern) == j)
			return i;	
	}	
	return -1;	
}

// Find the offset of the last occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchLastOccurrence(char *pattern, char *text)
{
	
	int i, j, index = -1;
	for(i = 0; i < strlen(text) - strlen(pattern); i++)
	{
		for(j = 0; (pattern[j] != '\0') && (pattern[j] == text[i + j]); j++);
		if(strlen(pattern) == j)
			index = i;	
	}	
	return index;
}

// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text)
{
	int i, j, count = 0;
	for(i = 0; i < strlen(text) - strlen(pattern); i++)
	{
		for(j = 0; (pattern[j] != '\0') && (pattern[j] == text[i + j]); j++);
		if(strlen(pattern) == j)
			count++;	
	}	
	return count;
}

// Find the length of longest prefix of the pattern that matches a substring of the pattern
int longestPrefix(char *pattern, char *text)
{
	int i, j, max = 0;
	for(i = 0; i < strlen(text) - strlen(pattern); i++)
	{
		for(j = 0; (pattern[j] != '\0') && (pattern[j] == text[i + j]); j++);
		if(max < j)
			max = j;
	}	
	return max;
}

// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text)
{
	int i, j, count = 0;
	for(i = 0; i <= strlen(text) - strlen(pattern); i++)
		for(j = 0; pattern[j] != '\0'; j++, count++)
			if(pattern[j] != text[i + j])
			{
				count++;
				break;
			}
	return count;
}

