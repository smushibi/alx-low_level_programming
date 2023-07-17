#include <stdio.h>
/**
 * main - Prints the lowercase alphabet in reverse order using an array
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
int i;
for (i = sizeof(alphabet) - 2; i >= 0; i--)
{
putchar(alphabet[i]);
}
putchar('\n');
return (0);
}
