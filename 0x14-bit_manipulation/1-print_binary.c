#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints binary form of no
 * @n: int
 * Return
 */
void print_binary(unsigned long int n)
{
	unsigned long int m = 1;

	m <<= ((sizeof(m) * 8) - 1);
	if (n == 1)
	{
		_putchar('1');
		return;
	}
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while (m > 0)
	{
		if ((m & n) == 0)
			m = m >> 1;
		else
			break;
	}
	while (m > 0)
	{
		if ((m & n) == 0)
			_putchar('0');
		else
			_putchar('1');
		m = m >> 1;
	}
}
