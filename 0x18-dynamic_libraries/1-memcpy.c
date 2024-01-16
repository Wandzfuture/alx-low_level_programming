#include "main.h"

/**
 * _memcpy - copies memory area.
 * @dest: destination for memory area.
 * @src: Is the source memory area.
 * @n: The bytes filled.
 *
 * Return: the pointer to (dest)
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) =  *(src + i);

	return (dest);
}
