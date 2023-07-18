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
		_putchar(43);
		return (1);
	}
	else if (n < 0)
	{
		-putchar(45);
		return (-1);
	}
	else
	{
		-putchar(48);
		return (0);
	}
	_putchar('\n');
}
