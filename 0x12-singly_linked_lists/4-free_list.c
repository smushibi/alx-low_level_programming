#include <stdlib.h>
#include "lists.h"

/**
* free_list - Free a linked list.
* @head: Pointer to the head of the list to be freed.
*/
void free_list(list_t *head)
{
list_t *current = head;
while (current != NULL)
{
list_t *temp = current;
current = current->next;
free(temp->str);
free(temp);
}
}
