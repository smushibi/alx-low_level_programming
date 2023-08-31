#include "main.h"
#include <stdio.h>

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the unsigned long int where the bit is to be set.
 * @index: The index of the bit to set (starting from 0).
 *
 * Return: 1 if the operation succeeded, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(*n) * 8)
return (-1);
*n = *n | (1UL << index);
return (1);
}
