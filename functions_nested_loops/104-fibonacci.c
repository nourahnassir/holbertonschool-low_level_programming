#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long f1_head = 0, f1_tail = 1;
	unsigned long f2_head = 0, f2_tail = 2;
	unsigned long next_head, next_tail;
	unsigned long limit = 1000000000;

	printf("%lu, %lu", f1_tail, f2_tail);

	for (count = 3; count <= 98; count++)
	{
		next_tail = f1_tail + f2_tail;
		next_head = f1_head + f2_head + (next_tail / limit);
		next_tail %= limit;

		printf(", ");
		if (next_head > 0)
			printf("%lu%09lu", next_head, next_tail);
		else
			printf("%lu", next_tail);

		f1_head = f2_head;
		f1_tail = f2_tail;
		f2_head = next_head;
		f2_tail = next_tail;
	}
	printf("\n");

	return (0);
}

