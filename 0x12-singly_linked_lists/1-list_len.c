#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* list_len - Count the number of elements in a linked list.
* @h: Pointer to the head of the list.
* Return: The number of elements in the list.
*/
size_t list_len(const list_t *h)
{
size_t count = 0;
for (; h != NULL; h = h->next)
{
count++;
}
return (count);
}
