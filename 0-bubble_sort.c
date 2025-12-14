#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 * @array: the array that has to be sorted
 * @size: of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i; 
	int temp;
	bool swapped = true;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (swapped)
	{
		swapped = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
	}
}

