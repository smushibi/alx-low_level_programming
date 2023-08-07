#include <stddef.h>
#include <string.h>
/**
 * _strncat - Custom strncat function to concatenate strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of characters to concatenate from src.
 *
 * Return: A pointer to the destination string (dest).
 */
char *_strncat(char *dest, const char *src, unsigned int n)
{
    size_t dest_len = strlen(dest);
    size_t i;

    /* Check if n is greater than the length of src */
    if (n > strlen(src))
        n = strlen(src);

    /* Copy the characters from src to the end of dest */
    for (i = 0; i < n; i++)
        dest[dest_len + i] = src[i];

    /* Null-terminate the resulting string */
    dest[dest_len + i] = '\0';

    return dest;
}

