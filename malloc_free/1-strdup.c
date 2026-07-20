#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	/* 1. حساب طول السلسلة */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* 2. حجز الذاكرة (+1 للـ \0) */
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	/* 3. نسخ الحروف */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

