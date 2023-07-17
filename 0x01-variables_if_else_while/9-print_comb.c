#include <stdio.h>
/**
 * main - Entry point of the program
 * Description: Prints the numbers 0 to 9 separated by spaces
 * Return: Always 0 (Success)
 */
int main(void)
{
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i;
for (i = 0; i < 10; i++)
{
putchar(digits[i]);
if (i % 3 == 0)
{
putchar(' ');
}
}
return (0);
}
