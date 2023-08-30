#include <stddef.h>
#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: A pointer to the head of the linked list.
 * Return: The number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
size_t element_count = 0;
while (h != NULL)
{
h = h->next;
element_count++;
}
return (element_count);
}
