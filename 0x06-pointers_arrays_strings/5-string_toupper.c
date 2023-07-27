#include "main.h"
#include <stdio.h>
#include <ctype.h>
/**
 * string_toupper - converts all lowercase letters in a string to uppercase
 * @str: the string to convert
 *
 * Return: a pointer to the modified string
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		str[i] = toupper(str[i]);
		i++;
	}
	return (str);
}
