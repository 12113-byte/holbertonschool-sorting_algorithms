#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swaps two elements
 * @a: first element
 * @b: second element
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
 * @low: starting index of current subarray
 * @high: ending index of current subarray
 * @size: of the array
 * Return: pointer to pivot
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

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
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		if (pivot_index > low)
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
	quick_sort_recursive(array, 0, (int)size - 1, size);
}

