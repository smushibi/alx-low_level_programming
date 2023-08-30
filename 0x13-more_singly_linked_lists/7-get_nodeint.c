#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 * @index: The index of the desired node (starting from 0).
 * Return: The nth node at the given index, or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int count;
listint_t *current;
for (count = 0, current = head;
current != NULL; count++, current = current->next)
{
if (count == index)
return (current);
}
return (NULL);
}
