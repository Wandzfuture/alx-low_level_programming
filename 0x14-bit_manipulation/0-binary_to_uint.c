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

	while (b[i] != '\0')
		i++;

	i--;

	while (i >= 0)
	{
		if (b[i] == '1')
			uint_dec += (1 << (strlen(b) - i - 1));
		else if (b[i] != '0')
			return (0);
		i--;
	}

	return (uint_dec);
}
