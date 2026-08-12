#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	long len, sum, v, i;
	char key[7];

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	len = strlen(argv[1]);
	sum = 0;
	for (i = 0; i < len; i++)
	{
		sum += argv[1][i];
	}

	key[0] = ((sum ^ 0x3b) & 0x3f) + 0x30;

	v = 1;
	for (i = 0; i < len; i++)
	{
		v *= argv[1][i];
	}
	key[1] = ((v ^ 0x48) & 0x3f) + 0x30;

	v = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > v)
			v = argv[1][i];
	}
	srand(v ^ 0xe5);
	key[2] = (rand() & 0x3f) + 0x30;

	v = 0;
	for (i = 0; i < len; i++)
	{
		v += argv[1][i] * argv[1][i];
	}
	key[3] = ((v ^ 0xe5) & 0x3f) + 0x30;

	v = 0;
	for (i = 0; i < len; i++)
	{
		v = rand();
	}
	key[4] = ((v ^ 0x229) & 0x3f) + 0x30;
	key[5] = '\0';

	printf("%s", key);
	return (0);
}
