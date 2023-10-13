#include "lists.h"
/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 * @head: A double pointer to the head of the list.
 * @n: The integer value for the new node.
 *
 * Return: A pointer to the newly added node,
 * or NULL if memory allocation fails.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newnode = malloc(sizeof(dlistint_t));

	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->prev = *head;
	newnode->n = n;
	newnode->next = NULL;

	if (*head != NULL)
	{
		(*head)->next = newnode;
	}
	*head = newnode;
	return (newnode);
}
