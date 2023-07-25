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
	int sign = 1, result = 0, digit, found_number = 0;

	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-' || *s == '+')
		sign = (*s++ == '-') ? -1 : 1;
	while (*s >= '0' && *s <= '9')
	{
		found_number = 1;
		digit = *s++ - '0';
		if (result > INT_MAX / 10 ||
				(result == INT_MAX / 10 && digit > INT_MAX % 10))
			return ((sign == -1) ? INT_MIN : INT_MAX);
		result = result * 10 + digit;
	}
	return ((found_number == 1) ? sign * result : 0);
}
