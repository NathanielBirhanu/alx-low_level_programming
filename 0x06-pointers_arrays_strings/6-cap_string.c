#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * cap_string - capitalizes the first letter of each word in a string
 * @str: the string to modify
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int is_word_start = 1;

	while (str[i] != '\0')
	{
		if (is_word_start && isalpha(str[i]))
		{
			str[i] = toupper(str[i]);
			is_word_start = 0;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == ',' || str[i] == ';' || str[i] == '.' ||
				str[i] == '!' || str[i] == '?' || str[i] == '"' ||
				str[i] == '(' || str[i] == ')' || str[i] == '{' ||
				str[i] == '}')
		{
			is_word_start = 1;
		}
		else
		{
			is_word_start = 0;
		}
		i++;
	}
	return (str);
}
