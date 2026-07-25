#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers
 * @min: The minimum value (included)
 * @max: The maximum value (included)
 *
 * Return: Pointer to the newly created array, or NULL if it fails
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	if (min > max)
		return (NULL);

	size = (max - min) + 1;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++, min++)
	{
		arr[i] = min;
	}

	return (arr);
}

