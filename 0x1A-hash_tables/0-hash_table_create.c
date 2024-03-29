#include"hash_tables.h"

/**
 * hash_table_create - hash table function
 * Description: a function that creates a hash table
 * @size: the size of the array
 * Return: a pointer to the newly created hash table
*/

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *hash_table = malloc(sizeof(hash_table_t));

	if (hash_table == NULL)
	{
	free(hash_table);
	return (NULL);
	}
	hash_table->size = size;
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
	free(hash_table);
	return (NULL);
	}
	for (i = 0; i < size; i++)
	{
	hash_table->array[i] = NULL;
	}
	return (hash_table);
}
