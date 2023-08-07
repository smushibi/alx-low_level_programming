#include <stddef.h>

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero
 *         depending on whether str1 is less than, equal to, or greater than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
    while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}
