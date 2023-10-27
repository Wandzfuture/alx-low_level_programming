#include <stdio.h>

/**
 * main - Prints all arguments it receives.
 * @argc: number of arguments
 * @argv: The array with the arguments.
 * Return: Always(0).
 **/
int main(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
