#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head != NULL)
	{
		next = (*head)->next; /* Store the next node */

		(*head)->next = prev; /* Reverse the pointer */

		prev = *head; /* Move the prev pointer */
		*head = next; /* Move the head pointer */
	}

	*head = prev;

	return (*head);
}
