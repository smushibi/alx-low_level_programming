 #include <string.h>
 #include "main.h"
/**
 * _strspn - Get the length of a prefix substring.
 * @s: The string to search.
 * @accept: The characters to search for.
 * Description: This function calculates the
 *length of the initial segment
 * of @s that consists entirely of
 *characters from @accept.
 * Return: The number of bytes in the
 *initial segment of @s which consists
 *only of bytes from @accept.
 */

unsigned int _strspn(char *s, char *accept)
{
unsigned int i = 0;
while (s[i] != '\0' && strchr(accept, s[i]) != NULL)
{
i++;
}
return (i);
}
