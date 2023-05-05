#include <unistd.h>

/**
 * _putchar - writes char c to stdout
 * @c: The character to print
 *
 * Return: 1 when correct
 * whn failed, -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
