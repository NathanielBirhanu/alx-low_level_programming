#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: Unsigned long int number to print in binary.
 *
 * Description: This function prints the binary representation
 *              of the given number.
 * Return: None.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int flag = 0;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	while (mask > 0)
	{
		if ((n & mask) == 0)
		{
			if (flag)
				putchar('0');
		}
		else
		{
			putchar('1');
			flag = 1;
		}

		mask >>= 1;
	}
}
