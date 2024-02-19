#include "sort.h"


/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence
 * @array: The array of integers
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (index = i; index >= gap && (array[index] < array[index - gap]); index -= gap)
			{
				swaap(array, index, index - gap);
			}
		}

		print_array(array, size);
		gap /= 3;
	}
}
