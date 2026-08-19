#include "main.h"

/**
 * check_len - helper function to get string length
 * @s: string
 * Return: length
 */
int check_len(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + check_len(s + 1));
}

/**
 * check_pal - helper function to check palindrome recursively
 * @s: string
 * @i: left index / iterator
 * @j: right index
 * Return: 1 if palindrome, 0 otherwise
 */
int check_pal(char *s, int i, int j)
{
	if (i >= j)
		return (1);
	if (s[i] != s[j])
		return (0);
	return (check_pal(s, i + 1, j - 1));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not.
 * @s: string to evaluate
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	if (*s == '\0')
		return (1);
	len = check_len(s);
	return (check_pal(s, 0, len - 1));
}
