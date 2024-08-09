#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *	in ascending order using the Insertion sort algorithm
 * @list: pointer of pointer to the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp1;
	listint_t *temp2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current)
	{
		temp1 = current->prev;
		temp2 = current->next;
		while (temp1 && current->n < temp1->n)
		{
			swap_nodes(list, temp1, current);
			print_list(*list);
			temp1 = current->prev;
		}
		current = temp2;
	}
}

/**
 * swap_nodes - swap the two given nodes
 * @list: pointer of pointer to the linked list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
