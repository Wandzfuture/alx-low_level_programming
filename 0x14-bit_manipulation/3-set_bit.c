#include "main.h"

/**
 * set_bit - function that Sets a bit at a given index to 1
 * @n: The pointer to the number to change
 * @index: The index of the bit to set to 1
 *
 * Return: (1) for success, (-1) for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL;

	if (index > (sizeof(unsigned long int) * 8 - 1) || n == NULL)
		return (-1);

	mask <<= index;
	*n |= mask;

	return (1);
}
