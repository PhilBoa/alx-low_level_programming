#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Pointer to the name of the file.
 * @text_content: String to add to the end of the file.
 *
 * Return: If function fails or filename is NULL, -1.
 * If file is non existence the user lacks write permissions, 1.
 * Otherwise, 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int op, wr, len = 0;

	if (filename == NULL)
	return (-1);
	if (text_content != NULL)
	{
	for (len = 0; text_content[len];)
	len++;
	}
	op = open(filename, O_WRONLY | O_APPEND);
	if (op == -1)
	{
	perror("Error");
	return (-1);
	}
	wr = write(op, text_content, len);
	if (wr == -1)
	{
	perror("Error");
	close(op);
	return (-1);
	}
	close(op);
	return (1);
}
