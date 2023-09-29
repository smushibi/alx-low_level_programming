#include "main.h"

/**
* print_binary - Prints the binary representation of a number.
* @n: The number to be printed in binary.
*
* Format: Binary representation of the number.
*
* You are not allowed to use arrays, malloc, % or / operators.
*/
void print_binary(unsigned long int n)
{
unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
int flag = 0;
while (mask > 0)
{
if ((n & mask) || flag)
{
if (n & mask)
_putchar('1');
else
_putchar('0');
flag = 1;
}
mask >>= 1;
}
if (!flag)
_putchar('0');
}
