#include "main.h"
/**
 * create_file - makes a file
 * @filename: name of file
 * @text_content: str to add
 * Return: 1 or -1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, n = 0;
	long int written;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[n])
			n++;
		written = write(fd, text_content, n);
		if (written == -1)
			return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (1);
}
