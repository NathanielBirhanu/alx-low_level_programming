#include "lists.h"

/**
 * print_list - Counts and prints the number of nodes in a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t count;
        const list_t *current = h;

	if (h == NULL)
	{
		printf("[0] (nil)");
		return (0);
	}
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	printf("%lu", count);
	return (count);
}
