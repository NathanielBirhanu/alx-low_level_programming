#include "main.h"
/**
 * flip_bits - Calculates the number of bits
 * needed to flip to get from one number to another.
 * @n: First unsigned long int number.
 * @m: Second unsigned long int number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	while (diff != 0)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}
