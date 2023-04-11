#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_file - Creates a file.
 * @filename: name of the file to created.
 * @text_content: string to write to the file.
 *
 * Return: If the function fails - 0.
 * Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int fr, wr, len = 0;

	if (filename == NULL)
	return (0);
	if (text_content != NULL)
	{
	for (len = 0; text_content[len];)
	len++;
	}
	fr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(fr, text_content, len);
	if (fr == 0 || wr == 0)
	{
	perror("Error");
	return (0);
	}
	close(fr);
	return (1);
}
