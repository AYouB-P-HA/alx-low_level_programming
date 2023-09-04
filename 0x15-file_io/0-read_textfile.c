#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer to the file
 * @letters: the number of letters it should read and print
 * Return: 0 or number of letters printed
 **/
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t op, rd, w;
	char *buff;

	if (!filename)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);

	op = open(filename, O_RDONLY);
	rd = read(op, buff, letters);
	w = write(STDOUT_FILENO, buff, rd);

	if (op == -1 || rd == -1 || w == -1)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(op);
	return (w);
}
