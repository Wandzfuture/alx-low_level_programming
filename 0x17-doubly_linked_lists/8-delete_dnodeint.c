#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index,
 * index of a dlistint_t linked list
 * @head: pointer to the pointer to the head of the list
 * @index: index of the node that should be deleted
 *
 * Return: (1) if it succeeded, (-1) if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *prev;
	unsigned int count;

	if (*head == NULL)
		return (-1);

	temp = *head;
	count = 0;

	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while (temp != NULL && count < index)
	{
		prev = temp;
		temp = temp->next;
		count++;
	}

	if (count != index || temp == NULL)
		return (-1);

	prev->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = prev;
	free(temp);

	return (1);
}
