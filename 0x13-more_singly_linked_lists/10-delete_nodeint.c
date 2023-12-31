#include "lists.h"

/**
 *delete_nodeint_at_index - deletes a node in a linked list at certain index
 *@head: pointer to the first element in list
 *@index: The index of the node to delete
 *
 *Return: 1 (Success), or -1 (Failure)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (temp != NULL && i < index - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL || temp->next == NULL)
		return (-1);

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
