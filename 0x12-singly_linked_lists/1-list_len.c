#include "lists.h"

/**
 * list_len - returns the num of elements in a linked list
 * @h: Is a pointer to the list_t list
 *
 * Return: number of elements in the list (n).
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}

	return (n);
}
