/**
 * _memcpy - Copies memory area.
 * @dest: Pointer to the destination memory area.
 * @src: Pointer to the source memory area.
 * @n: Number of bytes to be copied.
 *
 * Description: This func copies 'n' bytes from the memory area
 * pointed to by 'src'to the memory area pointed to by 'dest'.
 * The memory areas must not overlap.
 * Return: A pointer to the destination memory area ('dest').
 */
#include "main.h"

char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
dest[i] = src[i];
}
return (dest);
}

