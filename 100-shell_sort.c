#include "sort.h"

/**
 * swaapp - Swaps the positions of two elements in an array
 * @array: The array
 * @item1: Index of the first element
 * @item2: Index of the second element
 */
void swaapp(int *array, int item1, int item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}


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
		i = gap;
		while (i < size)
		{
			index = i;
			while (index >= gap && (array[index] < array[index - gap]))
			{
				swap(array, index, index - gap);
				index -= gap;
			}
			i++;
		}

		print_array(array, size);
		gap /= 3;
	}
}
