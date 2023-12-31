#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: Is memory area.
 * @b: The constant byte.
 * @n: The bytes filled.
 *
 * Return: Is the pointer to dest.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) =  b;

	return (s);
}
