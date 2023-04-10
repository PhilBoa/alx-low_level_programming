#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: pointing to a string of 0 and 1 chars
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *bin)
{
	int k;
	unsigned int result = 0;

	if (bin == NULL)
	return (0);
	for (k = 0; bin[k] != '\0'; k++)
	{
	if (bin[k] == '0' || bin[k] == '1')
	{
	result = (result << 1) + (bin[k] - '0');
	}
	else
	{
	return (0);
	}
	}
	return (result);
}
