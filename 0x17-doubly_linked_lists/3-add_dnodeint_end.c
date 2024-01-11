#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer value for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t* add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL;)

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/*traverse the list to the end */
	current = *head;
	while (current->next != NULL)
		current = current->next;

	new_node->prev = current;

	current->next = new_node;

	return (new_node);
}
