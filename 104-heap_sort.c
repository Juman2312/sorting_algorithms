#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Performs the sift down operation on a heap.
 * @array: Pointer to the array of integers.
 * @start: Index of the root of the heap.
 * @end: Index of the last element in the heap.
 * @size: Size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap;
	int tmp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;

		print_array(array, size);

		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (start = (size - 2) / 2; start > 0; start--)
		sift_down(array, start, size - 1, size);

	sift_down(array, 0, size - 1, size);

	for (end = size - 1; end > 0; end--)
	{
		tmp = array[0];
		array[0] = array[end];
		array[end] = tmp;

		print_array(array, size);

		sift_down(array, 0, end - 1, size);
	}
}
