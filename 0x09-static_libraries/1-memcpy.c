#include "main.h"

/**
 * _memcpy - Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 * @dest: Pointer to the destination memory area.
 * @src: Pointer to the source memory area.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to 'dest'.
 */
char *_memcpy(char *dest, char *src, unsigned int n) {
    char *dest_start = dest;
    while (n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    return dest_start;
}

