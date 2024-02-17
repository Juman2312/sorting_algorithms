#include "sort.h"

/**
 * swap - Swaps the positions of two nodes in a doubly linked list.
 * @a: Pointer to the first node to be swapped.
 * @b: Pointer to the second node to be swapped.
 *
 * Description: This function swaps the positions of two nodes in a doubly linked list.
 * It updates the necessary prev and next pointers to perform the swap.
 */

void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

}


/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using the insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: This function sorts a doubly linked list in ascending order
 * using the insertion sort algorithm.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *k;

	if (!list || !*list || !(*list)->next)
		return;
	i =(*list)->next;
	while (i)
	{
		k = i;
		i = i->next;
		while (k && k->prev)
		{

			if (k->prev->n > k->n)
			{

				swap (k->prev, k);
				if (!k->prev)
					*list = k;
				print_list((const listint_t *)*list);
			}

			else
				k = k->prev;
		}

	}
}
