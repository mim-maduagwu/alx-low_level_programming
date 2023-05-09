#include "main.h"
/**
 * append_text_to_file - appens str
 * @filename: name of file
 * @text_content: str to app
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	long int written;
	int fd, n = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
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
