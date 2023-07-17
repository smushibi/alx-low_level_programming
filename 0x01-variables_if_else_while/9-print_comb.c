#include <stdio.h>
/**
 * main - Entry point of the program
 * Description: Prints the numbers 0 to 9 separated by commas
 * Return: Always 0 (Success)
 */
int main(void)
{
char digits[] = "0, 1, 2, 3, 4, 5, 6, 7, 8, 9";
int i;
for (i = 0; digits[i] != '\0'; i++)
{
if (digits[i] != ' ')
putchar(digits[i]);
}
putchar('\n');
return (0);
}
