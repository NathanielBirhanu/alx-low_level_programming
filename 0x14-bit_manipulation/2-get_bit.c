#include "main.h"
/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: Unsigned long int number.
 * @index: Index of the bit to retrieve.
 *
 * Return: Value of the bit at the given index, or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;
	int bit;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /* Return -1 if the index is out of range */

	mask = 1UL << index;
	bit = (n & mask) ? 1 : 0; /* Check if the bit at the given index is set */

	return (bit);
}
