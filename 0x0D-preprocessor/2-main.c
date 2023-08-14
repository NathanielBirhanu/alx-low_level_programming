#include <stdio.h>
/**
 * main - prints the name of the file it was compiled from,
 * followed by a new line
 * Description: prints the name of the file it was compiled from,
 * followed by a new line.
 * Return: void
 */
int main(void)
{
	const char *filename = __FILE__;
	int i;

	for (i = 0; filename[i] != '\0'; i++)
	{
		putchar(filename[i]);
	}
	putchar('\n');
	return (0);
}
