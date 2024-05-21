#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array
 * by using exponential search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located,
 * or (-1) if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	int bound = 1;
	int left = bound / 2;
	int right = (bound < size) ? bound : size - 1;
	int mid, i;

	if (array == NULL)
		return (-1);

	if (size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%d] =[%d]\n", bound, array[bound]);
		bound *= 2;
	}

	printf("Value found between indexes[%d] and[%d]\n", left, right);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
		{
			printf("%d, ", array[i]);
		}

		printf("%d\n", array[i]);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
