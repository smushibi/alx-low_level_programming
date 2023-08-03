#include "main.h"
/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number for which the square root is to be calculated.
 * Return: The natural square root of the number, or -1 if not found.
 */
int _sqrt_recursion(int n)
{
if (n <= 0)
{
return (-1);
}
int approx = n / 2;
while (approx * approx != n)
{
if (approx * approx < n)
{
approx++;
}
else
{
approx--;
}
}
return (approx);
}
