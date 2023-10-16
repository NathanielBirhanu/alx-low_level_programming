#include "main.h"
#include "stdio.h"
/**
 * _strcpy - copies the string pointed to by src, including the
 *
 * @dest: a pointer to the buffer where the string will be copied
 * @src: a pointer to the string to be copied
 *
 * Return: a pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';

	return (dest);
}
