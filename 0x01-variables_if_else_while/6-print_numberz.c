#include <stdio.h>
/**
 * main - Prints numbers 0-9
 * using putchar not prinf or puts
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
for (i = 0; i < 10; i++)
{
putchar(i + '0');
}
putchar('\n');
return (0);
}
