#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int c;
	int d =  0;

	while (d < 10)
	{
		c = 10;
		while (c < 10)
		{
			putchar('0' + d);
			putchar('0' + c);
			if (c + d != 17)
			{
				putchar(',');
				putchar(' ');
				}
			}

		}
	c++;
	}
	d++;
	}
	putchar('\n');
return (0);
{
