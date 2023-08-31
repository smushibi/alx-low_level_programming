#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Calculates the number
 * of bits needed to flip between two numbers.
 * @n: The first unsigned long int.
 * @m: The second unsigned long int.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int diff = n ^ m;
unsigned int count = 0;
{
count += diff & 1;
diff >>= 1;
}
return (count);
}
