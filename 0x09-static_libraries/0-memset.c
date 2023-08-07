#include "main.h"

/**
 * _memset - Fills the first 'n' bytes of the memory area pointed to by 's'
 *           with the constant byte 'b'.
 * @s: Pointer to the memory area to be filled.
 * @b: The constant byte to be filled.
 * @n: Number of bytes to be filled.
 *
 * Return: Pointer to the memory area 's'.
 */
char *_memset(char *s, char b, unsigned int n) {
    char *start = s;
    while (n > 0) {
        *s = b;
        s++;
        n--;
    }
    return start;
}

