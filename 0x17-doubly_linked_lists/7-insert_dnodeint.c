#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the pointer to the head of the list
 * @idx: index of the list where the new node should be added
 * @n: integer to store in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t* insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int count;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*h == NULL)
	{
		*h = new_node;
		return (new_node);
	}

	if (idx == 0)
	{
		new_node->next = *h;
		(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	temp = *h;
	count = 0;
	while (temp != NULL && count < idx)
	{
		temp = temp->next;
		count++;
	}

	if (count != idx)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = temp;
	new_node->prev = temp->prev;
	temp->prev->next = new_node;
	temp->prev = new_node;

	return (new_node);
}
