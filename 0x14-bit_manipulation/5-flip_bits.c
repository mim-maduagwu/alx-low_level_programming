#include "main.h"
/**
 * flip_bits - fips bits
 * @n: initial no
 * @m: second no
 * Return: no neede to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip_no, count = 0;

	flip_no = n ^ m;
	while (flip_no > 0)
	{
		count += flip_no & 1;
		flip_no >>= 1;
	}
	return (count);
}
