#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * puts_half - prints half of a string,
 * followed by a new line
 *
 * @str: character parameter
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = strlen(str);
	int start_idx = len % 2 == 0 ? len / 2 : (len + 1) / 2;
	int i;

	for (i = start_idx; i < len; i++)
	{
		putchar(str[i]);
	}
	putchar('\n');
}
