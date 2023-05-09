#include "main.h"
/**
 * main - copier program
 * @ac: argv count
 * @av: array of arg
 * Return: int
 */
int main(int ac, char **av)
{
	char buff[1024];
	int fd_1, fd_2, written, reade;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_1 = open(av[1], O_RDONLY);
	if (fd_1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from %s\n", av[1]);
		exit(98);
	}
	fd_2 = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}
	while ((reade = read(fd_1, buff, 1024)) > 0)
	{
		written = write(fd_2, buff, reade);
		if (written == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", av[2]);
			exit(99);
		}
	}
	if (reade == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", av[1]);
		exit(98);
	}
	if (close(fd_1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d", fd_1);
		exit(100);
	}
	if (close(fd_2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d", fd_2);
		exit(100);
	}
	return (0);
}

