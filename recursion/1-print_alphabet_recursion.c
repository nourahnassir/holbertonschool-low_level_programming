#include "main.h"

/**
 * print_alpha - helper function to print alphabet recursively
 * @c: current character to print
 */
void print_alpha(char c)
{
	if (c > 'z')
	{
		_putchar('\n');
		return;
	}
	_putchar(c);
	print_alpha(c + 1);
}

/**
 * _print_alphabet_recursion - prints the alphabet in lowercase,
 * followed by a new line.
 *
 * Return: void
 */
void _print_alphabet_recursion(void)
{
	print_alpha('a');
}
