#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swaps two elements
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - divides an array based on a pivot element.
 * One pointer marks the boundary for elements smaller than the pivot.
 * @array: thearray being divided
 * @low:
 * @high:
 * @size:
 * Return:
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - sorts an array of integers etc.
 * @array: pointer to array
 * @low: starting index of current subarray
 * @high: ending index of current subarray
 * @size: of array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		if (pivot_index > 0)
		{
			quick_sort_recursive(array, low, pivot_index - 1, size);/*Left partition*/
		}
		quick_sort_recursive(array, pivot_index + 1, high, size);/*Right partition*/
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: pointer to array
 * @size: of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}

