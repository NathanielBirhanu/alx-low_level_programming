#include "main.h"
#include <stdio.h>

/**
 * rot13 - encodes a string using rot13
 * @str: the string to encode
 *
 * Return: a pointer to the encoded string
 */
char *rot13(char *str)
{
	int i, j;
	char c;

	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		for (j = 0; j < 13 && c != '\0'; j++)
		{
			if ((c >= 'a' && c <= 'm') ||
					(c >= 'A' && c <= 'M'))
			{
				c += 13;
			}
			else if ((c >= 'n' && c <= 'z') ||
					(c >= 'N' && c <= 'Z'))
			{
				c -= 13;
			}
		}
		str[i] = c;
	}
	return (str);
}
