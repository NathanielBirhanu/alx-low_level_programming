#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	*h = NULL; /* Set the head to NULL to indicate an empty list */

	while (current != NULL)
	{
		count++;
		temp = current;
		current = current->next;
		free(temp);

		/* Check if the next node is already visited */
		if (current == *h)
		{
			current = NULL;
			break;
		}
	}

	return (count);
}
