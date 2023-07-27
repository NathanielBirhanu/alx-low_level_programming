#include "main.h"
#include <stdio.h>
/**
 * leet - encodes a string into 1337
 * @str: the string to encode
 *
 * Return: a pointer to the encoded string
 */
char *leet(char *str)
{
	int i, j;
	char leet_chars[] = "AEGOTL";
	char leet_nums[] = "436017";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leet_chars[j] != '\0'; j++)
		{
			if (str[i] == leet_chars[j] ||
					str[i] == leet_chars[j] + 32)
			{
				str[i] = leet_nums[j];
				break;
			}
		}
	}
	return (str);
}
