#include "lists.h"

/**
 * dlistint_len - Return the number of elements in linked dlistint_t list.
 * @h: Pointer to the head of the list
 *
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	if (h == NULL)
		return (count);

	/* Traverse to the beginning of the list */
	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
