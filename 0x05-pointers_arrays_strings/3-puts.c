#include "main.h"
#include <stdio.h>
/**
 * _puts - prints a string,
 * followed by a new line, to stdout
 * @str: character parameter
 * Return: nothing
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		*str++;
	}
	putchar('\n');
}
