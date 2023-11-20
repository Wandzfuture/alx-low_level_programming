#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at certain index
 * @head: pointer to the first element in the list
 * @index: The index of the node to delete
 *
 * Return: 1 (Success), or EXIT_FAILURE (-1)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*head == NULL)
	{
		return (EXIT_FAILURE);
	}

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (EXIT_SUCCESS);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (EXIT_FAILURE);
		temp = temp->next;
		i++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (EXIT_SUCCESS);
}
