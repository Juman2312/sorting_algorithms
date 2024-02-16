#include "sort.h"


void bubble_sort(int *array, size_t size);
{
	int temp;
	size_t i= 0;
	size_t j;

	if(!array || !size)
		return;

	while (i < size)
	{
		for (j = 0, j < size, j++)
		{
			if(array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array.size);
			}
		}
		i++;
	}

}
