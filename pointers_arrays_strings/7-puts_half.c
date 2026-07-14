#include "main.h"

/**
 * puts_half - Prints half of a string, followed by a new line.
 * @str: The string to be printed.
 *
 * Return: void.
 */
void puts_half(char *str)
{
	int len = 0;
	int start_index;

	/* 1. Calculate the length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* 2. Determine the starting index based on even or odd length */
	if (len % 2 == 0)
	{
		start_index = len / 2;
	}
	else
	{
		start_index = len - ((len + 1) / 2);
	}

	/* 3. Print the second half of the string */
	while (str[start_index] != '\0')
	{
		_putchar(str[start_index]);
		start_index++;
	}

	_putchar('\n');
}

