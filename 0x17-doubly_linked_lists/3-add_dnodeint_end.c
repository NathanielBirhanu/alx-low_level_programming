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
        dlistint_t *temp = *head;

        if (newnode == NULL)
        {
                return (NULL);
        }

        newnode->n = n;
        newnode->next = NULL;

        if (*head == NULL)
        {
                newnode->prev = NULL;
                *head = newnode;
                return (newnode);
        }

        while (temp->next != NULL)
        {
                temp = temp->next;
        }

        newnode->prev = temp;
        temp->next = newnode;

        return (newnode);
}
