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
	int i = 0;
	int j = length - 1;

	while (i < j)
	{
		char temp = s[i];

		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
