#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all numbers of base 16 in lowercase.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 0;
	char ch = 'a';

	while (n < 10)
	{
		putchar(n + '0');
		n++;
	}

	while (ch <= 'f')
	{
		putchar(ch);
		ch++;
	}

	putchar('\n');

	return (0);
}
