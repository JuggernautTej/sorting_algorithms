#include "sort.h"

/**
 * swap_nodes - swaps two nodes in the list
 * @list: a pointer to a pointer to the head of the list
 * @node1: a pointer to the first node
 * @node2: a pointer to the second node
 * Return: void
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	/* return if list is empty */
	if (!node1 || !node2 || node1 == node2)
		return;

	/* Update next pointers */
	if (node1->next)
		node1->next->prev = node2;
	if (node2->next)
		node2->next->prev = node1;

	temp = node1->next;

	node1->next = node2->next;
	node2->next = temp;

	/* Update prev pointers */
	if (node1->next)
		node1->next->prev = node1;
	if (node2->next)
		node2->next->prev = node2;

	/* Update prev poniters for the nodes being swapped */
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->prev)
		node2->prev->next = node1;

	temp = node1->prev;

	node1->prev = node2->prev;
	node2->prev = temp;

	/* Update hea pointer if needed */
	if (*list == node1)
		*list = node2;
	else if (*list == node2)
		*list = node1;
}

/**
 * insertion_sort_list - sorts the list in ascendind order with
 *			insertion sort algorithm
 * @list: a pointer to a pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;
	listint_t *prev;

	if (!list || !*list || !(*list)->next)
		return;

	while (curr)
	{
		prev = curr->prev;

		while (prev && prev->n > curr->n)
		{
			swap_nodes(list, prev, curr);
			print_list(*list);

			prev = curr->prev;
		}
		curr = curr->next;
	}
}
