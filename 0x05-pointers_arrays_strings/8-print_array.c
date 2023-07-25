#include "main.h"
/**
 * print_array - Prints n elements of an array using _putchar.
 * @a: Pointer to the array.
 * @n: Number of elements of the array to be printed.
 */
void print_array(int *a, int n)
{
int i;
for (i = 0; i < (n - 1); i++)
{
_putchar('0' + a[i]);
_putchar(',');
_putchar(' ');
}
if (i == (n - 1))
{
_putchar('0' + a[n - 1]);
}
_putchar('\n');
}
