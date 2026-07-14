#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] == '+')
		{
			/* Do nothing */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			res = (res * 10) - (s[i] - '0');
		}
		else if (found == 1)
		{
			break;
		}
		i++;
	}

	if (sign == 1)
	{
		return (-res);
	}
	return (res);
}

