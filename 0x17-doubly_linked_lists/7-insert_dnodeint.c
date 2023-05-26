#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - insert function
 * DESCRIPTION: a function that inserts a new
 *				node at specific index of a
 *				doubly linked list
 * @h: pointer to the first node passed to the function
 * @idx: the index to be inerted at
 * @n: the node data
 * Return: address of the new node
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *temp;
	unsigned int count = 0;

	if (h == NULL)
		return (NULL);
	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	if (idx == 0)
	{
		node->next = *h;
		node->prev = NULL;
		if (*h != NULL)
			(*h)->prev = node;
		*h = node;
		return (node);
	}
	temp = *h;
	while (temp != NULL)
	{
		if (count == idx - 1)
		{
			node->next = temp->next;
			node->prev = temp;
			if (temp->next != NULL)
				temp->next->prev = node;
			temp->next = node;
			return (node);
		}
	count++;
	temp = temp->next;
	}
	free(node);
	return (NULL);
}
