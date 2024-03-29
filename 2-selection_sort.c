#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp, swaps;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		swaps = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				swaps++;
			}
		}

		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
		}

		if (swaps > 0)
			print_array(array, size);
	}
}
