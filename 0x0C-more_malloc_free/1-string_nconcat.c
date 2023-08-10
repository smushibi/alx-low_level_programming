#include <stdlib.h>
#include <string.h>
#include  "main.h"

/**
 * string_nconcat - Concatenates two strings with a
 * limit on the second string
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes from s2 to concatenate
 *
 * Return: Pointer to the newly allocated
 *         concatenated string
 *         If memory allocation fails or
 *         inputs are NULL, returns NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
unsigned int len1;
unsigned int len2;
char *result;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
len1 = strlen(s1);
len2 = strlen(s2);
if (n >= len2)
n = len2;
result = malloc(len1 + n + 1);
if (result == NULL)
return (NULL);
strcpy(result, s1);
strncat(result, s2, n);
return (result);
}
