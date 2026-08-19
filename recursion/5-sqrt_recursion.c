#include "main.h"

/**
 * check_sqrt - helper function to find the natural square root
 * @n: the number to find the square root of
 * @i: the iterator/guess number
 *
 * Return: the natural square root, or -1 if none exists
 */
int check_sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (check_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: the number
 *
 * Return: the natural square root, or -1 if n does not have one
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (check_sqrt(n, 0));
}
