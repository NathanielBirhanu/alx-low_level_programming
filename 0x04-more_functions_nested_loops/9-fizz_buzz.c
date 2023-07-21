#include <stdio.h>
/**
 * main - prints the numbers from 1 to 100,
 * followed by a new line
 * But for multiples of three print Fizz instead of the number
 * and for the multiples of five print Buzz.
 * For numbers which are multiples of both three and five print FizzBuzz
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
		{
			putchar(' ');
			putchar('F');
			putchar('i');
			putchar('z');
			putchar('z');
		}
		else if (i % 5 == 0 && i % 3 != 0)
		{
			putchar(' ');
			putchar('B');
			putchar('u');
			putchar('z');
			putchar('z');
		}
		else if (i % 3 == 0 && i % 5 == 0)
		{
			putchar(' ');
			putchar('F');
			putchar('i');
			putchar('z');
			putchar('z');
			putchar('B');
			putchar('u');
			putchar('z');
			putchar('z');
		}
		else if (i == 1)
		{
			putchar(i + '0');
		}
		else
		{
			putchar(' ');
			putchar(i + '0');
		}
	}
	putchar('\n');
	return (0);
}
