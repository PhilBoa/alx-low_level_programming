#include "hash_tables.h"

/**
 * key_index - function that return a key index
 * @key: key to get it's index
 * @size: size of the array of the hash table
 *
 * Return: the index at which the key/value pair
 *			should be stored in the array of the
 *			hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_val = hash_djb2(key);
	unsigned long int idx = hash_val % size;

	return (idx);
}
