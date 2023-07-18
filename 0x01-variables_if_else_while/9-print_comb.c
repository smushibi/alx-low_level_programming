#include <stdio.h>
/**
 * main - Entry point of the program
 * Description: Prints the numbers 0 to 9 separated by spaces
 * Return: Always 0 (Success)
 */
int main(void)
{
int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i;
for (i = 0; i < 10; i++)
{
putchar(digits[i] + '0');
if (i == 2 || i == 5 || i == 8) {
putchar(' ');
}
}
return (0);
}
