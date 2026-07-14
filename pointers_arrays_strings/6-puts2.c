#include "main.h"

/**
 * puts2 - Prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str: The string to be printed.
 *
 * Return: void.
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		
		/* إذا كان الحرف الحالي هو الأخير، نخرج لكي لا نتجاوز حدود الذاكرة */
		if (str[i + 1] == '\0')
		{
			break;
		}
		
		/* نقفز خطوتين للأمام */
		i += 2;
	}
	_putchar('\n');
}

