
#include "main.h"
/**
 * print_diagsums - Print the sum of the two
 * diagonals of a square matrix.
 * @a: The 2D array representing the square matrix.
 * @size: The size of the square matrix.
 */
void print_diagsums(int *a, int size)
{
int sum1 = 0;
int sum2 = 0;
int i;
for (i = 0; i < size; i++)
{
sum1 += a[i * size + i];
sum2 += a[i * size + (size - i - 1)];
}
_putchar(sum1);
_putchar(sum1);
}
