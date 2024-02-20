#include "sort.h"
#include <stdio.h>

/**
 * _calloc - allocates memory for an array using calloc
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		ptr[i] = '\0';

	return (ptr);
}

/**
 * merge - merges two subarrays into one sorted array
 * @array: original array
 * @tmp: temporary array used for merging
 * @start: starting index of the first subarray
 * @mid: ending index of the first subarray
 * @end: ending index of the second subarray
 */
void merge(int *array, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1, size_right = end - mid;
	int *left_array, *right_array;
	int left, right, i = 0;

	left_array = &tmp[0];
	right_array = &tmp[size_right];

	for (left = 0; left < size_left; left++)
		left_array[left] = array[start + left];

	for (right = 0; right < size_right; right++)
		right_array[right] = array[mid + 1 + right];

	left = 0;
	right = 0;
	i = start;

	while (left < size_left && right < size_right)
	{
		if (left_array[left] <= right_array[right])
			array[i] = left_array[left++];
		else
			array[i] = right_array[right++];
		i++;
	}

	while (left < size_left)
		array[i++] = left_array[left++];

	while (right < size_right)
		array[i++] = right_array[right++];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, left);
	printf("[right]: ");
	print_array(right_array, right);
	printf("[Done]: ");
	print_array(&array[start], left + right);
}

/**
 * merge_sort_recursive - recursively sorts the array
 * @array: array to be sorted
 * @tmp: temporary array used for merging
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 */
void merge_sort_recursive(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;

	if (mid >= start)
	{
		merge_sort_recursive(array, tmp, start, mid);
		merge_sort_recursive(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = _calloc(size, sizeof(int));
	merge_sort_recursive(array, tmp, 0, size - 1);
	free(tmp);
}
