#include "lists.h"
#include <stdio.h>

void print_dlistint(dlistint_t *head)
{
	    dlistint_t *current = head;
	    
	    for (; current != NULL; current = current->next)
	    {
	    printf("%d\n", current->n);
	    }
}
