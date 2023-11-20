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
	const listint_t *current = h;

	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
		num++;
	}

	printf("\n");
	return (num);
}
