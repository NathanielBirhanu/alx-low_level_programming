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

	while (*s)
	{
		if (*s == '-')
		{
			sign = -sign;
			s++;
		}
		else if (*s == '+')
		{
			s++;
		}
		else if (*s >= '0' && *s <= '9')
		{
			found_number = 1;
			digit = *s - '0';
			if (result > INT_MAX / 10 ||
					(result == INT_MAX / 10 && digit > INT_MAX % 10))
			{
				return (sign == 1 ? INT_MAX : INT_MIN);
			}
			result = result * 10 + digit;
			s++;
		} else
		{
			if (found_number)
			{
				break;
			}
			else
			{
				s++;
			}
		}
	}
	return (sign * result);
}
