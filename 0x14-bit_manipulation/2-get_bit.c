#include "main.h"

/**
 * get_bit - gets the value of a bit at a given index
 * @n: Unsigned long integer
 * @index: Index of the bit to retrieve
 *
 * Return: Value of bit at given index, or (-1) if index is invalid
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	{
		return (-1);
	}

	bit_val = (n >> index) & 1;

	return (bit_val);
}
