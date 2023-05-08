#include <stddef.h>
#include "main.h"
/**
 * read_textfile - reads from a .txt
 * @filename: name of file
 * @letters: no of letters in bytes
 * Return: count of letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	int fd, prints, written;

	buff = malloc(letters * sizeof(char));
	if (buff == NULL)
		return (0);
	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (0);
	prints = read(fd, buff, letters);
	if (prints == -1)
		return (0);
	written = write(STDOUT_FILENO, buff, prints);
	if (written == -1)
		return (0);
	if (close(fd) == -1)
		return (0);
	free(buff);
	return (prints);
}
