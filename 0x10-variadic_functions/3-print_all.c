#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints values based on the given format string
 * @format: A string containing the format specifiers
 *            c: char
 *            i: integer
 *            f: float
 *            s: char * (if the string is NULL, print (nil) instead)
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;

	va_start(args, format);

	const char *ptr = format;
	int integer;
	float floating;
	char *str;

	while (*ptr != '\0')
	{
		if (*ptr == 'c')
		{
			int character = va_arg(args, int);

			printf("%c", character);
		}
		else if (*ptr == 'i')
		{
			integer = va_arg(args, int);
			printf("%d", integer);
		}
		else if (*ptr == 'f')
		{
			floating = va_arg(args, double);
			printf("%f", floating);
		}
		else if (*ptr == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
		}
		ptr++;
	}
	va_end(args);
	printf("\n");
}
