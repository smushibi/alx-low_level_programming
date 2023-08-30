#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a
 * given position in the list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @idx: The index where the new node should be added (starting from 0).
 * @n: The value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 *         If it's not possible to add the new node at the
 * specified index, return NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int count = 0;
listint_t *new_node, *current;
if (head == NULL)
return (NULL);
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = NULL;
if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
current = *head;
while (current != NULL && count < idx - 1)
{
current = current->next;
count++;
}
if (current == NULL || current->next == NULL)
{
free(new_node);
return (NULL);
}
new_node->next = current->next;
current->next = new_node;
return (new_node);
}
