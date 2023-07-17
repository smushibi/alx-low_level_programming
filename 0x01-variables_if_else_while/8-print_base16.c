#include <stdio.h>
/**
 * main - Entry point of the program
 * Description: Prints all the numbers of base 16 in lowercase
 * Return: Always 0 (Success)
 */
int main(void)
{
char alp[] = "0123456789abcdef";
int i;
for (i = 0; i < 16 ; i++)
{
putchar(alp[i]);
}
putchar('\n');
return (0);
}
