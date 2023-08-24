#include "lists.h"

/**
 * print_list - Counts and prints the number of nodes in a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	if (h == NULL)
	{
		printf("[0] (nil)");
		return (0);
	}
	size_t count = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	printf("%zu", count);
	return (count);
}
