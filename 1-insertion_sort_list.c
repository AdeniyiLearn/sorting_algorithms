#include "sort.h"

/**
 * change_list - changes node in a linkedlist.
 * @list: double to the list at which nodes are exchanged.
 * @first_node: double pointer to the 1st_node
 * @second_node: pointer to the 2nd node to swap.
 * Return: void.
 */
void change_list(listint_t **list, listint_t **first_node,
		listint_t *second_node)
{
	(*first_node)->next = second_node->next;

	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
	else
		*list = second_node;

	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}


/**
 * insertion_sort_list - sort doubly linked list of integers
 * in ascending order with Insertion sort algorithm;
 * @list: double pointer to the list to be sorted.
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *now, *tmp, *tmp_prev;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	now = (*list)->next;
	while (now != NULL)
	{
		tmp = now->next;
		tmp_prev = now->prev;
		while (tmp_prev != NULL && now->n < tmp_prev->n)
		{
			change_list(list, &tmp_prev, now);
			print_list(*list);

		}
		now = tmp;
	}
}
