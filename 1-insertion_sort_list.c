#include "sort.h"


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
