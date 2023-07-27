#include <stdio.h>
#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: the first number to add
 * @n2: the second number to add
 * @r: the buffer to store the result
 * @size_r: the size of the buffer
 *
 * Return: a pointer to the result, or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int carry = 0;
    int i, j;

    if (len1 + 1 > size_r || len2 + 1 > size_r)
        return 0;

    for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--)
    {
        int digit1 = i >= 0 ? n1[i] - '0' : 0;
        int digit2 = j >= 0 ? n2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }

        if (i + j + 2 > size_r)
            return 0;
        r[i + j + 1] = sum + '0';
    }

    if (carry && len1 + len2 + 2 <= size_r)
    {
        r[0] = carry + '0';
        r[len1 + len2 + 1] = '\0';
        return &r[0];
    }
    else if (!carry)
    {
        r[len1 + len2] = '\0';
        return &r[1];
    }
    else
    {
        return 0;
    }
}
