#include <stdio.h>
#include <stdarg.h>
/**
 * sum_them_all - Calculates the sum of all its parameters.
 * @n: The number of arguments.
 * Return: The sum of all the parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	if (n == 0)
		return (0);
	int total = 0;
	va_list args;

	va_start(args, n);
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		int num = va_arg(args, int);

		total += num;
	}
	va_end(args);
	return (total);
}
