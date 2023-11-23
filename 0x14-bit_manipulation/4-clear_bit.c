#include "main.h"

/**
 * clear_bit - function that sets the value of a given bit to 0
 * @n: the pointer to the number to change
 * @index: the index of the bit to clear
 *
 * Return: (1) for success, (-1) for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL;

	if (index > (sizeof(unsigned long int) * 8 - 1) || n == NULL)
		return (-1);

	mask <<= index;
	mask = ~mask;
	*n &= mask;

	return (1);
}
