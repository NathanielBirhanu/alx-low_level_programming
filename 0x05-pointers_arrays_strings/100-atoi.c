#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer.
 * @s: the string to convert.
 *
 * Return: the integer value of the string.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int digit;

	while (*s == ' ' || *s == '\t' || *s == '\n' ||
			*s == '\v' || *s == '\f' || *s == '\r')
	{
		s++;
	}

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		sign = 1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		digit = *s - '0';

		if (result < INT_MIN / 10 ||
				(result == INT_MIN / 10 && digit > -(INT_MIN % 10)))
		{
			/* Overflow detected */
			return (sign == 1 ? INT_MAX : INT_MIN);
		}

		result = result * 10 - digit;
		s++;
	}

	return (sign * result);
}
