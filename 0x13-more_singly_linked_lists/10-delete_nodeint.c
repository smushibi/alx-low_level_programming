#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given
 *index of a listint_t linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @index: The index of the node to be deleted (starting from 0).
 *
 * Return: 1 if the deletion succeeded, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int count = 0;
listint_t *temp, *prev;
if (head == NULL || *head == NULL)
return (-1);
if (index == 0)
{
temp = *head;
*head = (*head)->next;
free(temp);
return (1);
}
prev = NULL;
temp = *head;
while (temp != NULL && count < index)
{
prev = temp;
temp = temp->next;
count++;
}
if (temp == NULL)
return (-1);
prev->next = temp->next;
free(temp);
return (1);
}
