#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with malloc
 * @old_size: Size in bytes of the allocated space for ptr
 * @new_size: New size in bytes of the new memory block
 *
 * Return: Pointer to the newly allocated memory block
 *         If ptr is NULL, behaves like malloc(new_size)
 *         If new_size is 0 and ptr is not NULL, behaves like
 *         free(ptr) and returns NULL
 *         If new_size is equal to old_size, returns ptr without changes
 *         If malloc fails, returns NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;
unsigned int i;
if (ptr == NULL)
return (malloc(new_size));
if (new_size == 0)
{
free(ptr);
return (NULL);
}
if (new_size == old_size)
return (ptr);
new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);
if (new_size > old_size)
new_size = old_size;
for (i = 0; i < new_size; i++)
{
*((char *)new_ptr + i) = *((char *)ptr + i);
}
free(ptr);
return (new_ptr);
}
