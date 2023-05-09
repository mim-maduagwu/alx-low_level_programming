#include "main.h"
/**
 * __exit - prints error messages and exits with exit value
 * @err: exit val or fd valu
 * @s: file name
 * @fd: file descriptor
 * Return: int
 */
int __exit(int err, char *s, int fd)
{
	switch (err)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(err);
	case 98:
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", s);
		exit(err);
	case 99:
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", s);
		exit(err);
	case 100:
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
		exit(err);
	default:
		return (0);
	}
}
/**
 * main - file copier
 * @ac: argv count
 * @av: argument array
 * Return: 0, or 97-100
 */
int main(int ac, char **av)
{
	int fd_f, fd_t, reade, written;
	char *buff[1024];

	if (ac != 3)
		__exit(97, NULL, 0);

	fd_t = open(av[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_t == -1)
		__exit(99, av[2], 0);

	fd_f = open(av[1], O_RDONLY);
	if (fd_f == -1)
		__exit(98, av[2], 0);

	while ((reade = read(fd_f, buff, 1024)) != 0)
	{
		if (reade == -1)
			__exit(98, av[1], 0);
		written = write(fd_t, buff, reade);
		if (written == -1)
			__exit(99, av[2], 0);
	}

	close(fd_t) == -1 ? (__exit(100, NULL, fd_t)) : close(fd_t);
	close(fd_f) == -1 ? (__exit(100, NULL, fd_f)) : close(fd_f);
	return (0);
}
