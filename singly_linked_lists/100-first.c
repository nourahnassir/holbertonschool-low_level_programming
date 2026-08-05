#include <stdio.h>

void print_start(void) __attribute__ ((constructor));

/**
 * print_start - Prints a specific sentence before the main
 *               function is executed.
 *
 * Return: Nothing.
 */
void print_start(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
