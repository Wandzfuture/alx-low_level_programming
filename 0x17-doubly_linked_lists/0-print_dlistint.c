#include "lists.h"

/**
 * print_dlistint - Prints all the elemts of a doubly linked list
 * @h: Pointer to the head of the list
 *
 * Return: Number of nodes (count)
 */

size_t print_dlistint(const dlistint_t *h);
{
	size_t count = 0;
	Node *temp = h;
	
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		count++;
		temp = temp->next;
	}

	return (count);
}
