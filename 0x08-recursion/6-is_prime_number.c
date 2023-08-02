#include <stdio.h>
#include "main.h"
/**
 * is_prime_number - eturns 1 if the input integer is a prime number,
 * otherwise return 0
 * @n: integer parameter
 * Return: integer
 */
int is_prime_number(int n)
{
	int i;
	int flag;

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			flag = 1;
			break;
		}
		else
			flag = 0;
	}
	if (flag == 1)
		return (0);
	else
		return (1);
}
