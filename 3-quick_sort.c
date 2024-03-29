#include "sort.h"

/**
 * swaap - Swaps the positions of two elements in an array
 * @array: The array
 * @item1: Index of the first element
 * @item2: Index of the second element
 */
void swaap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme implementation
 * @array: The array
 * @first: The first index of the array
 * @last: The last index of the array
 * @size: Size of the array
 *
 * Return: The position of the last element after sorting
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swaap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		swaap(array, current, last);
		print_array(array, size);
	}

	return (current);
}

/**
 * qs - Quicksort algorithm implementation
 * @array: The array
 * @first: The first index of the array
 * @last: The last index of the array
 * @size: Size of the array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qs(array, 0, size - 1, size);
}

