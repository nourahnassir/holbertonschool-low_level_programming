#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: the main string to search within
 * @needle: the substring to look for
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *h_ptr;
	char *n_ptr;

	if (*needle == '\0')
	{
		return (haystack);
	}

	while (*haystack != '\0')
	{
		h_ptr = haystack;
		n_ptr = needle;

		while (*h_ptr == *n_ptr && *n_ptr != '\0')
		{
			h_ptr++;
			n_ptr++;
		}

		if (*n_ptr == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}

