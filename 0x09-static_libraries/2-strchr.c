#include <stddef.h>

/**
 * _strchr - Locates the first occurrence of c (character) in the string pointed to by str.
 * @str: The string to search.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence of c in str, or NULL if c is not found.
 */
const char *_strchr(const char *str, int c)
{
    const char *ptr;

    for (ptr = str; *ptr != '\0'; ptr++)
        if (*ptr == c)
            return ptr;

    return NULL;
}

