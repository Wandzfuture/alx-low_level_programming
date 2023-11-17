#include "lists.h"

/**
 * free_list - is a function that frees a linked list
 * @head: Is the list_t list to be freed
 *
 * return: void(nothing).
 */
void free_list(list_t *head)
{
	list_t * temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
