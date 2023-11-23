#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: the number to print binary representation.
 */
void print_binary(unsigned long int n)
{
	int i;
	int leading_zero = 0;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	for (i = sizeof(n) * 8 - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			leading_zero = 1;
			_putchar('1');
		}
		else if (leading_zero)
		{
			_putchar('0');
		}
	}
}
