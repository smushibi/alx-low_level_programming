#include "main.h"

/**
 * _strspn - Calculates the length of the initial segment of 's'
 *           which consists entirely of characters from 'accept'.
 * @s: Pointer to the string to be checked.
 * @accept: Pointer to the string containing the characters to match.
 *
 * Return: The number of characters in the initial segment of 's'
 *         that consists only of characters from 'accept'.
 */
unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;
    while (*s != '\0') {
        char *accept_char = accept;
        while (*accept_char != '\0') {
            if (*s == *accept_char) {
                count++;
                break;
            }
            accept_char++;
        }
        if (*accept_char == '\0') {
            break;
        }
        s++;
    }
    return count;
}

