#include "main.h"

/**
 * _strncat - Concatenates at most n characters from src to dest.
 * @dest: The destination string.
 * @src: The source string to be concatenated.
 * @n: The maximum number of characters to concatenate.
 *
 * Return: The pointer to the destination string.
 */
char *_strncat(char *dest, char *src, int n) {
    char *dest_end = dest;
    while (*dest_end != '\0') {
        dest_end++;
    }

    while (n > 0 && *src != '\0') {
        *dest_end = *src;
        dest_end++;
        src++;
        n--;
    }
    *dest_end = '\0';
    return dest;
}

