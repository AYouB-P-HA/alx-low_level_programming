#include "main.h"

/**
 * create_file - creates a file.
 * @filename: pointer to the name of the file
 * @text_content: is a NULL terminated string to write to the file
 * Return: -1 or 1
 **/
int create_file(const char *filename, char *text_content)
{
	int op, w, num;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (num = 0; text_content[num];)
			num++;
	}

	op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(op, text_content, num);

	if (op == -1 || w == -1)
		return (-1);

	close(op);
	return (1);
}
