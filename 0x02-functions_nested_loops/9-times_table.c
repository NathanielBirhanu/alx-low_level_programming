#include "main.h"
/**
 * times_table - prints the 9 times table, starting with 0
 * Return: no return
 */
void times_table(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			int p = i * j;

			if (p < 10)
			{
				_putchar(p + '0');
			}
			else
			{
				_putchar('0' + p / 10);
				_putchar('0' + p % 10);
			}
			_putchar(',');
			_putchar(' ');
		}
		_putchar('\n');
	}
}
