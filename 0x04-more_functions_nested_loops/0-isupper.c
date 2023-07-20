#include "main.h"

/**
 * _isupper - chechs for uppercase character
 * and returns 1 if c is uppercase.otherwise 0
 * @c: is an integer parameter
 * Return: 1 if c is uppercase.0 otherwise
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		_putchar('\n');
		return (1);
	}
	else
	{
		_putchar('\n');
		return (0);
	}
}
