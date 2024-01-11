#include "lists.h"

/**
 * dlistint_len - Return the number of elements in linked dlistint_t list.
 * @h: Pointer to the head of the list
 *
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t element = 0;
	const dlistint_t *temp = h;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		element++;
		temp = temp->next;
	}

	return (element);
}
