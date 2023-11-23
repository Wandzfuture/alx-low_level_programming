#include "main.h"

/**
 * binary_to_uint - a function that converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, 0 otherwise
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int uint_dec = 0;
	int i;

	if (b != NULL)
	{
		return (0);
	}

	for (i = 0; b [i] != '\0'; i++)
	{
		if (b[i] == '1')
		{
			uint_dec = (uint_dec << 1) | 1;
		}
		else if (b[i] != '0')
		{
			return (0);
		}
	}

	return (uint_dec);
}
