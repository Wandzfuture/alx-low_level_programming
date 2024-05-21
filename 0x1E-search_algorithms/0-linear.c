#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers using,
 * the Linear search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search for
 *
 * Return: The index of the first occurrence of the value, or
 * (-1) if the value is not found or the array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	if (array == NULL)
	{
		return (-1);
	}

	for (size_t i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}
