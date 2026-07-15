#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for result
 * @size_r: buffer size
 *
 * Return: pointer to result, or 0 if it fails
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, x;
	int sum, carry = 0;

	while (n1[i])
		i++;
	while (n2[j])
		j++;
	if (i >= size_r || j >= size_r)
		return (0);
	i--;
	j--;
	size_r--;
	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		carry = sum / 10;
		if (k >= size_r)
			return (0);
		r[k++] = (sum % 10) + '0';
	}
	r[k] = '\0';
	for (x = 0; x < k / 2; x++)
	{
		char tmp = r[x];

		r[x] = r[k - 1 - x];
		r[k - 1 - x] = tmp;
	}
	return (r);
}
