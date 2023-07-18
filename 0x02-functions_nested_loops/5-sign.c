#include "main.h"
/**
 * print_sign - prints sign of numbers
 * either +, -, 0
 * @n: is an integer number
 * Return: 1 and prints + for numbers greater than 0,
 * -1 and - for numbers less than 0
 * and 0 and 0 for 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		-putchar('0');
		return (0);
	}
	else
	{
		-putchar('-');
		return (-1);
	}
	_putchar('\n');
}
