#include "main.h"

/**
 * set_bit - puts bit to index of 1
 * @n: number pointer change
 * @index: put index of the bit to 1
 *
 * Return: 1 for success or -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	{
	return (-1);
	}
	*n = ((1ul << index) | *n);
	return (1);
}
