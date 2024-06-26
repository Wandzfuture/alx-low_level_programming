#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using jump search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located,
 * or (-1) if not found.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0, curr;

	if (array == NULL)
		return (-1);

	while (prev < size && array[prev] < value)
	{
		curr = prev + step;
		printf("Value checked array[%lu] =[%d]\n", curr, array[curr]);
		if (curr >= size || array[curr] >= value)
			break;
		prev = curr;
	}

	printf("Value found between indexes[%lu] and[%lu]\n", prev, curr);

	while (prev < size && array[prev] <= value)
	{
		printf("Value checked array[%lu] =[%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		++prev;
	}

	return (-1);
}
