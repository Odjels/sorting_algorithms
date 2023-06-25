#include "sort.h"

/**
 * swap_nd_front - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shak: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_nd_front(listint_t **list, listint_t **tail, listint_t **shak)
{
	listint_t *tmp = (*shak)->next;

	if ((*shak)->prev != NULL)
		(*shak)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shak)->prev;
	(*shak)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shak;
	else
		*tail = *shak;
	(*shak)->prev = tmp;
	tmp->next = *shak;
	*shak = tmp;
}

/**
 * swap_nd_back - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shak: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_nd_back(listint_t **list, listint_t **tail, listint_t **shak)
{
	listint_t *tmp = (*shak)->prev;

	if ((*shak)->next != NULL)
		(*shak)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shak)->next;
	(*shak)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shak;
	else
		*list = *shak;
	(*shak)->next = tmp;
	tmp->prev = *shak;
	*shak = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shak;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shak = *list; shak != tail; shak = shak->next)
		{
			if (shak->n > shak->next->n)
			{
				swap_nd_front(list, &tail, &shak);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shak = shak->prev; shak != *list;
				shak = shak->prev)
		{
			if (shak->n < shak->prev->n)
			{
				swap_nd_back(list, &tail, &shak);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
