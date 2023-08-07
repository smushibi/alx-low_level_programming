#include "main.h"

/**
 * _strcpy - Copies a string to a destination buffer.
 * @dest: The destination buffer.
 * @src: The source string to be copied.
 *
 * Return: The pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src) {
    char *dest_start = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_start;
}

