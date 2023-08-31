#include "main.h"
#include <stddef.h> /* for NULL */
#include <string.h> /* for strlen */

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is one or more chars
 *         in the string @b that is not 0 or 1, or if @b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int bit;
	size_t i;

	if (b == NULL)
		return (0);

	for (i = 0; i < strlen(b); i++)
	{
		bit = b[i] - '0';

		if (bit != 0 && bit != 1)
			return (0);

		result = (result << 1) | bit;
	}

	return (result);
}
