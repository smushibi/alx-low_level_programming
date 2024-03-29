#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* print_list - prints all the elements of a list_t list.
* @h: name of the list
* Return: the number of nodes.
*/
size_t print_list(const list_t *h)
{
size_t count = 0;
for (; h != NULL; h = h->next, count++)
{
if (h->str == NULL)
{
printf("[0] (nil)\n");
}
else
{
printf("[%d] %s\n", h->len, h->str);
}
}
return (count);
}
