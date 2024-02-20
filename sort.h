#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void swap(listint_t *a, listint_t *b);
void selection_sort(int *array, size_t size);
void swaap(int *array, ssize_t item1, ssize_t item2);
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size);
void qs(int *array, ssize_t first, ssize_t last, int size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swaapp(int *array, int item1, int item2);
void *_calloc(unsigned int nmemb, unsigned int size);
void merge(int *array, int *tmp, int start, int mid, int end);
void merge_sort_recursive(int *array, int *tmp, int start, int end);
void merge_sort(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
void cocktail_sort_list(listint_t **list);
void *_calloc(unsigned int nmemb, unsigned int size);
void counting_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void heap_sort(int *array, size_t size);

#endif
