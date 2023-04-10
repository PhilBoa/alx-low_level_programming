#include "main.h"

/**
 * flip_bits - counts to change the number of bits
 * from number one to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int k, counts = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (k = 63; k >= 0; k--)
	{
	current = exclusive >> k;
	if (current & 1)
	{
	counts++;
	}
	}
	return (counts);
}
