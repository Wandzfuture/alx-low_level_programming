#include "main.h"

/**
 * _puts_recursion - is a function like puts();
 * @s: The input
 * Return: Always (0) Success
 */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}

	else
		_putchar('\n');
}
