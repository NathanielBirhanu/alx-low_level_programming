#include "main.h"
/**
 * swap_int - swaps the values of two integers.
 * @a: the value of integer to be swapped
 * @b: the value of integer to be swapped
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int *r;

	*r = *a;
	*a = *b;
	*b = *r;
}
