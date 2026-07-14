#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: The string to be reversed.
 *
 * Return: void.
 */
void rev_string(char *s)
{
	int len = 0;
	int start = 0;
	int end;
	char temp;

	/* 1. Calculate the length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	end = len - 1;

	/* 2. Swap characters from both ends towards the center */
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}

