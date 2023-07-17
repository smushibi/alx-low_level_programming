#include <stdio.h>
/**
 * main - Prints numbers 9-0 in reverse order
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
for (i = 9; i >= 0; i--)
{
putchar(i + '0');
}
putchar('\n');
return (0);
}
