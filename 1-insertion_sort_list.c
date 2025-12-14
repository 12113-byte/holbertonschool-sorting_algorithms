#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes
 * in a doubly linked list
 * @list: pointer to head of list
 * @a: first node
 * @b: second node
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b)
	{
		return;
	}

	/*update previous pointer*/
	if (b->next)
	{
		b->next->prev = a;
	}

	/*update next pointer*/
	if (a->prev)
	{
		a->prev->next = b;
	}
	else
	{
		/*update head if a was head*/
		*list = b;
	}

	/*swap a and b pointers*/
	a->next = b->next;
	b->prev = a->next;
	b->next = a;
	a->prev = b;
}

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order usin ghte Insertion sort algorithm
 * @list: pointer to head of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
		current = current->next;
	}
}

