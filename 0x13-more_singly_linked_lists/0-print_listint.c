#include "lists.h"

/**
 * print_listint - is a function that prints all the elements of a linked list
 * @h: linked list of type listint_t to print.
 *
 * Return: Is the number of nodes(num).
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
		printf("%d ", h->n);
		num++;
		h = h->next;
	}

	printf("\n");
	return (num);
}
