#include <string.h>
#include <stdio.h>
#include "main.h"
/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * Return: Pointer to the resulting string @dest.
 */
char *_strcat(char *dest, char *src)
{
int dest_len = strlen(dest);
int src_len = strlen(src);
memmove(dest + src_len, dest + dest_len, strlen(dest) - dest_len + 1);
memcpy(dest + dest_len, src, src_len);
return (dest);
}
