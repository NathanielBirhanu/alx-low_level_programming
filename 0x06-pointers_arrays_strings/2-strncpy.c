#include "main.h"
#include <string.h>
/**
 * _strncpy - copies a string up to n bytes
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
