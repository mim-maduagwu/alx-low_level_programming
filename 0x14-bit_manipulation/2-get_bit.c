#include "main.h"
/**
 * get_bit - finds bit at index
 * @n: number
 * @index: index to find
 * Return: int val or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 32)
		return (-1);

	return (n >> index & 1);
}
