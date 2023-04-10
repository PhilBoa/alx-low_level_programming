#include "main.h"

/**
 * get_endianness - finds if a char is little or big endian
 * Return: 1 for big and -1 for little
 */

int get_endianness(void)
{
	unsigned int k = -1;
	char *ch = (char *) &k;

	if (*ch)
	{
	return (-1);
	}
	else
	{
	return (1);
	}
}
