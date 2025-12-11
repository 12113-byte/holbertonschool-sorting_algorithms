#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 * @array: the array that has to be sorted
 * @size: of the array
 */

void bubble_sort(int *array, size_t size)
{
	int i, j, *temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; )
		{
			if (array[i] > array[j + 1])
			{
				*temp = array[j + 1];
				array[j + 1] = array[i];
				array[j] = *temp;
				printf("%i", array);
			}
		}
	}
}

