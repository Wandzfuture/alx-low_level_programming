#include "main.h"

/**
 * _isalpha - Check if character is a alphabet character.
 * @c: int character.
 *
 * Return: (1) if letter, lowercase/uppercase,
 * (0) otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);

	else
		return (0);
}
