#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Allocates memory for an array
 * and initializes it to zero
 * @nmemb: Number of elements in the array
 * @size: Size of each element
 *
 * Return: Pointer to the allocated memory
 *         If nmemb or size is 0, or if malloc fails, returns NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int i;
void *ptr;
char *char_ptr;
if (nmemb == 0 || size == 0)
return (NULL);
ptr = malloc(nmemb * size);
if (ptr == NULL)
return (NULL);
char_ptr = (char *)ptr;
for (i = 0; i < nmemb * size; i++)
{
char_ptr[i] = 0;
}
return (ptr);
}
