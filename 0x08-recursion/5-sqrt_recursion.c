#include "main.h"
/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number for which the square root is to be calculated.
 * Return: The natural square root of the number, or -1 if not found.
 */

int _sqrt_recursion(int n)
{
int i;
if (n <= 0)
{
return (-1);
}
for (i = 1; i * i <= n; i++)
{
if (i * i == n)
{
return (i);
}
}
return (-1);
}
