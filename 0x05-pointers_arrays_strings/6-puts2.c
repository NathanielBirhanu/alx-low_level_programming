#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * puts2 - prints every other character of a string,
 * starting with the first character,
 * followed by a new line
 *
 * @str: a pointer to the string to be printed
 *
 * Return: void
 */
void puts2(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str += 2;
	}
	putchar('\n');
}
