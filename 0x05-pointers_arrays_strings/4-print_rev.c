#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * print_rev - prints a string, in reverse,
 * followed by a new line
 * @s: character parameter
 * Return: nothing
 */
void print_rev(char *s)
{
	int length = strlen(s);
	int i = length - 1;

	while (i >= 0)
	{
		putchar(s[i]);
		i--;
	}
	putchar('\n');
}
