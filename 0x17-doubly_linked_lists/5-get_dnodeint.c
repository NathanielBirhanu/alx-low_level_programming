#include "lists.h"
#include <stddef.h>

/**
 * Definition for doubly-linked list.
 * struct dlistint_s {
 *     int n;
 *     struct dlistint_s *prev;
 *     struct dlistint_s *next;
 * };
 * typedef struct dlistint_s dlistint_t;
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index) {
    if (head == NULL)
        return NULL;

    dlistint_t *current = head;
    unsigned int count = 0;

    while (current != NULL) {
        if (count == index)
            return current;

        current = current->next;
        count++;
    }

    return NULL;
}
