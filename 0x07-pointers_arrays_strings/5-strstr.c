
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include  "main.h"

/**
 * _strstr - Locate a substring.
 * @haystack: The string to search in.
 * @needle: The substring to search for.
 *
 * Description: This function finds the first
 *   occurrence of the substring @needle
 *  in the string @haystack. If the substring
 *  is found, it returns a pointer to the
 *  beginning of the located substring;
 *  otherwise, it returns (NULL).
 *
 * Return: (NULL) if the substring is
 * not found, otherwise a pointer to
 * the beginningof the located substring
 * @needle in @haystack.
 */
char *_strstr(char *haystack, char *needle)
{
int n_haystack, n_needle;
if (!haystack || !needle)
return (NULL);
n_haystack = 0;
while (haystack[n_haystack] != '\0')
{
n_needle = 0;
while (needle[n_needle] != '\0' &&
haystack[n_haystack + n_needle] == needle[n_needle])
n_needle++;
if (needle[n_needle] == '\0')
return (&haystack[n_haystack]);
n_haystack++;
}
return (NULL);
}
