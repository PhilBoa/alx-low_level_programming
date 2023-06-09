#include"hash_tables.h"
/**
 * hash_table_print - function that prints a hash table
 * @ht: the hash table to print
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int flag = 0;
	hash_node_t *node;

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		if (node == NULL)
			continue;
		else
		{
			while (node != NULL)
			{
				if (node->next == NULL && i == ht->size - 1)
					flag = 1;
				printf("'%s': '%s'", node->key, node->value);
				if (!flag)
					printf(", ");
				node = node->next;
				flag = 0;
			}
		}
	}
	printf("}");
	printf("\n");
}
