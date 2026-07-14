#include "main.h"

/**
 * print_rev - Prints a string, in reverse, followed by a new line.
 * @s: The string to print.
 *
 * Return: void.
 */
void print_rev(char *s)
{
	int len = 0;
	int i;

	/* Get string length */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Print in reverse */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	_putchar('\n');
}

