#include <stdio.h>
/**
 * main - prints all three digit possible outcomes
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j, k;

	for (i = 48; i <= 56; i++)
	{
		for (j = 49; j <= 57; j++)
		{
			for (k = 50; k <= 58; k++)
			{
				if (k > j && j > i)
				{
					putchar(i);
					putchar(j);
					putchar(k);
					if (i != 56 || j != 57 || k != 58)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
}
