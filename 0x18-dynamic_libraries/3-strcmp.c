#include "main.h"
#include <string.h>
/**
 * _strcmp - compares two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: difference between ASCII codes of first non-matching characters,
 * or difference between ASCII codes of final characters if strings are equal
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
}
