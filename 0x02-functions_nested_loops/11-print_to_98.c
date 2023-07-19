#include <stdio.h>
#include "main.h"
/**
 * print_to_98 - prints all natural numbers from n to 98,
 * followed by a new line
 * @n: print from this number
 */
void print_from_n_to_98(int n)
{
printf("%d, ", n);
for (int i = n + 1; i < 99; i++)
{
printf("%d, ", i);
}
printf("%d\n", 98);
return (0);
}
