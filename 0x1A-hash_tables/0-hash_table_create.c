#include "hash_tables.h"

/*
 * hash_table_create - creates a hash table of a specified size
 * @size: the size of the hash table to create
 *
 * Return: a pointer to the newly created hash table,
 * or (NULL) if an error occurred
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(hash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (unsigned long int i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}
