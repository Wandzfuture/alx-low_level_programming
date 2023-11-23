#include "main.h"

/**
 * flip_bits - Counts the number of bits to change
 * to get from one number to another
 * @n: the first number
 * @m: The second number
 *
 * Return: The number of bits changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int exclusive = n ^ m;
	unsigned int count = 0;

	while (exclusive > 0)
	{
		count += exclusive & 1;
		exclusive >>= 1;
	}

	return (count);
}
