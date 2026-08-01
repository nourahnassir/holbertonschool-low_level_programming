#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format
 * @format: list of types of arguments passed to the function
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j = 0;
	char *str;
	char *sep = "";

	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == "cifs"[j])
			{
				printf("%s", sep);
				if (format[i] == 'c')
					printf("%c", va_arg(args, int));
				if (format[i] == 'i')
					printf("%d", va_arg(args, int));
				if (format[i] == 'f')
					printf("%f", (float)va_arg(args, double));
				if (format[i] == 's')
				{
					str = va_arg(args, char *);
					if (!str)
						str = "(nil)";
					printf("%s", str);
				}
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}

