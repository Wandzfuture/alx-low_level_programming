#include "main.h"

/**
 * _print_rev_recursion - Prints the  string in reverse.
 * @s: Is the string to be printed.
 */
void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
