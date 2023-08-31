#include "main.h"
#include <stdio.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the unsigned long int where the bit is to be cleared.
 * @index: The index of the bit to clear (starting from 0).
 *
 * Return: 1 if the operation succeeded, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(*n) * 8)
return (-1);
*n = *n & ~(1UL << index);
return (1);
}
