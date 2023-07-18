#include "main.h"
/**
 * print_last_digit - prints the last digit
 * of integer numbers
 *
 * @n: input number as integer
 *
 * Return: last digit
 */
int print_last_digit(int n)
{
	int m;

	m = n % 10;
	if (n < 0)
	{
		_putchar(-m + 48);
		return (-m);
	}
	else
	{
		_putchar(m + 48);
		return (m);
	}
}
