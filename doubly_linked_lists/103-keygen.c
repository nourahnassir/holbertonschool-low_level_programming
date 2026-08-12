#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a key for crackme5 based on the username
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *username;
	int len, i, sum = 0, ch;
	char key[7];

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	username = argv[1];
	len = strlen(username);

	for (i = 0; i < len; i++)
	{
		sum += username[i];
	}

	key[0] = ((sum ^ 59) & 63) + 48;

	sum = 1;
	for (i = 0; i < len; i++)
	{
		sum *= username[i];
	}
	key[1] = ((sum ^ 72) & 63) + 48;

	ch = 0;
	for (i = 0; i < len; i++)
	{
		if (username[i] > ch)
			ch = username[i];
	}
	srand(ch ^ 229);
	key[2] = (rand() & 63) + 48;

	ch = 0;
	for (i = 0; i < len; i++)
	{
		ch += username[i] * username[i];
	}
	key[3] = ((ch ^ 229) & 63) + 48;

	ch = 0;
	for (i = 0; i < username[0]; i++)
	{
		ch = rand();
	}
	key[4] = ((ch ^ 229) & 63) + 48;
	key[5] = '\0';

	printf("%s", key);
	return (0);
}
