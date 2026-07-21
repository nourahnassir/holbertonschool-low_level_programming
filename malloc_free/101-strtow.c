#include "main.h"
#include <stdlib.h>

/**
 * count_words - helper function to count words in a string
 * @str: string to evaluate
 * Return: number of words
 */
int count_words(char *str)
{
	int i, words = 0, in_word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (!in_word)
			{
				in_word = 1;
				words++;
			}
		}
		else
		{
			in_word = 0;
		}
	}
	return (words);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
	char **tab;
	int i, j, k, len, words, w = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	words = count_words(str);
	if (words == 0)
		return (NULL);

	tab = malloc((words + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0' && w < words; i++)
	{
		if (str[i] != ' ')
		{
			len = 0;
			for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
				len++;
			tab[w] = malloc((len + 1) * sizeof(char));
			if (tab[w] == NULL)
			{
				for (w = w - 1; w >= 0; w--)
					free(tab[w]);
				free(tab);
				return (NULL);
			}
			for (k = 0; k < len; k++, i++)
				tab[w][k] = str[i];
			tab[w][k] = '\0';
			w++;
		}
	}
	tab[w] = NULL;
	return (tab);
}
