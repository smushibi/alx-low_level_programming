#include  <stdio.h>
#include  "main.h"
/**
 * _strpbrk - Search a string for any of a set of bytes.
 * @s: The string to search.
 * @accept: The characters to search for.
 *
 * Description: This function searches @s for the first occurrence of any
 * character in the string @accept. The search stops at the first match found.
 *
 * Return: If a match is found, a pointer to the byte in @s that matches one of
 * the bytes in @accept is returned. If no match is found, NULL is returned.
 */
char *_strpbrk(char *s, char *accept)
{
char *p;
for (; *s != '\0'; s++)
for (p = accept; *p != '\0'; p++)
{
if (*s == *p)
return (s);
}
return (NULL);
}
