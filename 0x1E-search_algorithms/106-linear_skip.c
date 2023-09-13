#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where value is located, or
 *			NULL if not found.
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev;

	if (list == NULL)
		return (NULL);

	current = list;
	while (current != NULL)
	{
		prev = current;
		if (current->express == NULL)
		{
			while (current->next != NULL)
				current = current->next;
			break;
		}
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		if (current->n >= value)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);
	current = prev;
	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		if (current->n == value)
			return (current);
		else if (current->n > value)
			return (NULL);
		current = current->next;
	}
	return (NULL);
}
