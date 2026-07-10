#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n = 612852475143;
	long int div = 2;

	while (n != div)
	{
		if (n % div == 0)
		{
			n = n / div;
		}
		else
		{
			div++;
		}
	}
	printf("%ld\n", div);

	return (0);
}

