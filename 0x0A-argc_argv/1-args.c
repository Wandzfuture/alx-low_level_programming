#include <stdio.h>

/**
 * main - Prints the number of arguments passed into it.
 * @argc: The number of arguments.
 * @argv: The array with the arguments.
 * Return: Always(0)
 **/
int main(int argc, char *argv[])
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
