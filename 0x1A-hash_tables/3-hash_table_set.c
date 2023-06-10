#include"hash_tables.h"

/**
 * hash_table_set - function that add elements into the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: key to get it's index
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
	{
		return (0);
	}

	idx = key_index((const unsigned char *)key, ht->size);
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		return (0);
	}

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	return (1);
}
