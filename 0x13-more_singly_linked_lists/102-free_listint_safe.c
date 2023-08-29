#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *current, *next_node;
    size_t count = 0;

    if (h == NULL)
        return 0;

    current = *h;
    while (current != NULL)
    {
        count++;
        next_node = current->next;
        free(current);
        current = next_node;
        if (current == *h)
        {
            *h = NULL;
            break;
        }
    }

    return count;
}
