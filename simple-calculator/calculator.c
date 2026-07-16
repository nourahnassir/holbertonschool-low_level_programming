#include <stdio.h>

/**
 * main - Entry point for the simple calculator program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice = -1;
	int a, b;
	int c;

	while (choice != 0)
	{
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Invalid choice\n");
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice == 1)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			printf("B: ");
			if (scanf("%d", &b) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			printf("Result: %d\n", a + b);
		}
		else if (choice == 2)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			printf("B: ");
			if (scanf("%d", &b) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			printf("Result: %d\n", a - b);
		}
		else if (choice == 3)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			printf("B: ");
			if (scanf("%d", &b) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			printf("Result: %d\n", a * b);
		}
		else if (choice == 4)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			printf("B: ");
			if (scanf("%d", &b) != 1)
			{
				printf("Invalid number\n");
				while ((c = getchar()) != '\n' && c != EOF)
					;
				continue;
			}
			if (b == 0)
				printf("Error: division by zero\n");
			else
				printf("Result: %g\n", (double)a / b);
		}
		else if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
		}
	}

	return (0);
}

