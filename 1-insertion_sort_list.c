#include "sort.h"

/**
 * swapin_node - Swap two nodes in a doubly-linked list.
 * @h: head of the doubly-linked list.
 * @n1: first node to swap.
 * @n2: The second node to swap.
 */
void swapin_node(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *flab, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (flab = (*list)->next; flab != NULL; flab = temp)
	{
		temp = flab->next;
		insert = flab->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swapin_node(list, &insert, flab);
			print_list((const listint_t *)*list);
		}
	}
}
