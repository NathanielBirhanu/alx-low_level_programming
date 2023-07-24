#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * rev_string - reverses a string
 * @s: character parameter
 * Return: nothing
 */
void rev_string(char *s)
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
