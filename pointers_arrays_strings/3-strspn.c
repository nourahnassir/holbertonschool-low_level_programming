#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the main string to check
 * @accept: the string containing the allowed characters
 *
 * Return: the number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, found;

	while (*s != '\0')
	{
		found = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				count++;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			return (count);
		}
		s++;
	}

	return (count);
}

