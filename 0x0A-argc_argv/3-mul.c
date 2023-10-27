#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that multiplies two numbers.
 * @argc: The number of arguments.
 * @argv: The array with the arguments.
 * Return: Always(0).
 **/
int main(int argc, char *argv[])
{
	int mult = 0;
	char c[] = "Error";

	if (argc != 3)
	{
		printf("%s\n", c);
		return (1);
	}
	mult = atoi(argv[1]) * atoi(argv[2]);
	printf("%i\n", mult);
	return (0);
}
