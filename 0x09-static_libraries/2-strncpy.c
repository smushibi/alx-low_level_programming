#include "main.h"

/**
 * _strncpy - Copies at most n characters from src to dest.
 * @dest: The destination buffer.
 * @src: The source string to be copied.
 * @n: The maximum number of characters to copy.
 *
 * Return: The pointer to the destination buffer.
 */
char *_strncpy(char *dest, char *src, int n) {
    char *dest_start = dest;
    while (n > 0 && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }
    return dest_start;
}

