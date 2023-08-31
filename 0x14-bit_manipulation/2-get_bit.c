#include "main.h"
#include <stdio.h>

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The unsigned long int to retrieve the bit from.
 * @index: The index of the bit to retrieve (starting from 0).
 *
 * Return: The value of the bit at the specified
 * index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int mask;
if (index >= sizeof(n) * 8)
return (-1);
mask = 1UL << index;
if ((n & mask) == 0)
return (0);
else
return (1);
}

