#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>
#include <stdio.h>
#include<stdlib.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer value stored in the node
 * @prev: points to the previous node in the list
 * @next: points to the next node in the list
 *
 * Description: Node structure for a doubly linked list.
 */
typedef struct dlistint_t
{
    int n;
    struct dlistint_t *next;
    struct dlistint_t *prev;
} dlistint_t;

size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
int sum_dlistint(dlistint_t *head);

#endif
