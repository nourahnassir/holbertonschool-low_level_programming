#include "main.h"

/**
 * print_rev - Prints a string, in reverse, followed by a new line.
 * @s: The string to print.
 *
 * Return: void.
 */
void print_rev(char *s)
{
	int len = 0;
	int i;

	/* الخطوة 1: حساب طول النص للوصول للنهاية */
	while (s[len] != '\0')
	{
		len++;
	}

	/* الخطوة 2: الطباعة بالعكس بدءاً من الحرف الأخير */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	/* الخطوة 3: طباعة سطر جديد */
	_putchar('\n');
}

