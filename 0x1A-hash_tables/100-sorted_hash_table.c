#include"hash_tables.h"
/**
 * shash_table_create - hash table function
 * Description: a function that creates a hash table
 * @size: the size of the array
 * Return: a pointer to the newly created sorted hash table
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *hash_table = malloc(sizeof(shash_table_t));

	if (hash_table == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		hash_table->array[i] = NULL;
	}

	hash_table->shead = NULL;
	hash_table->stail = NULL;
	return (hash_table);

}
/**
 * shash_table_set - function that add elements into the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: key to get it's index
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *new_node, *curr_node, *prev_node;

	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	curr_node = ht->array[idx];
	while (curr_node != NULL)
	{
		if (strcmp(curr_node->key, key) == 0)
		{
			free(curr_node->value);
			curr_node->value = strdup(value);
			return (1);
		}
		curr_node = curr_node->next;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	prev_node = NULL;
	curr_node = ht->shead;
	while (curr_node != NULL && strcmp(curr_node->key, key) < 0)
	{
		prev_node = curr_node;
		curr_node = curr_node->snext;
	}

	if (prev_node == NULL)
		ht->stail = new_node;
	else
		new_node->snext->sprev = new_node;

	return (1);
}
/**
 * shash_table_get - function that retrieves a value associated with a key
 * @ht: the hash table to look into
 * @key: key to looking for
 *
 * Return: the value associated with the element,
 *			or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *node;

	if (ht == NULL || key == NULL || key[0] == '\0')
	{
		return (NULL);
	}

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
	node = node->next;
	}

	return (NULL); /* Key not found */
}
/**
 * shash_table_print - function that prints a hash table
 * @ht: the hash table to print
 *
 */
void shash_table_print(const shash_table_t *ht)
{
	int flag = 0;
	shash_node_t *node;

	if (ht == NULL)
	{
		return;
	}

	node = ht->shead;
	printf("{");
	/*if (node == NULL)*/
		/*continue;*/
	while (node != NULL)
	{
		if (node->snext == NULL)
			flag = 1;
		printf("'%s': '%s'", node->key, node->value);
		if (!flag)
		printf(", ");
		node = node->snext;
		flag = 0;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - function that prints a hash table in reverse
 * @ht: the hash table to print
 *
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int flag = 0;

	if (ht == NULL)
	{
		return;
	}

	node = ht->stail;
	printf("{");
	/*if (node == NULL)*/
		/*continue;*/

	while (node != NULL)
	{
		if (node->sprev == NULL)
		{
			flag = 1;
		}
		printf("'%s': '%s'", node->key, node->value);
		if (!flag)
		{
			printf(", ");
		}
		node = node->sprev;
		flag = 0;
	}

	printf("}\n");
}

/**
 * shash_table_delete - function that deletes a hash table
 * @ht: the hash table
 *
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node;
	shash_node_t *next_node;

	if (ht == NULL)
	{
		return;
	}

	node = ht->shead;
	while (node != NULL)
	{
		next_node = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = next_node;
	}

	free(ht->array);
	free(ht);
}
