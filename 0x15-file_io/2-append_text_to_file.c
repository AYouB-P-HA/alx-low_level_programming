#include "main.h"
#include <string.h>

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: pointer to the name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 **/
int append_text_to_file(const char *filename, char *text_content)
{
	int op, w;
    int length = 0;
	if (filename == NULL)
		return (-1);

	op = open(filename, O_WRONLY | O_APPEND);
    w = write(op, text_content, length);
	if (text_content != NULL)
	{
		length = strlen(text_content);
	}

	if (op == -1 || w == -1)
		return (-1);

	close(op);
	return (1);
}
