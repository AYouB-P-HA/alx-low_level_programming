#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - program that copies the content of a file to another file.
 * @argc: number of arguments passed to the function main
 * @argv: stores the arguments passed to the function
 * Return: 0
 **/
int main(int argc, char *argv[])
{
 	int file_from, file_to, r, w;
	int err_cff, err_cft;
 	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDOUT_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDOUT_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDOUT_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	do
	{
		r = read(file_from, buff, 1024);
		if (r == -1)
		{
			dprintf(STDOUT_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		w = write(file_to, buff, r);
		if (w == -1)
		{
			dprintf(STDOUT_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}

	} while (r > 0);

	err_cff = close(file_from);
	err_cft = close(file_to);

	if (err_cff == -1)
	{
		dprintf(STDOUT_FILENO, "Error: Can't close fd %d\n", file_from
);
		exit(100);
	}

	if (err_cft == -1)
	{
		dprintf(STDOUT_FILENO, "Error: Can't close fd %d\n",file_to);
		exit(100);
	}

	return (0);
}
