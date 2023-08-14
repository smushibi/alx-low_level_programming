#include <stdlib.h>
#include "main.h"

/**
 * is_positive_integer - Checks if a string is a positive integer
 * @str: The string to be checked
 *
 * Return: 1 if the string is a positive integer, 0 otherwise
 */
int is_positive_integer(const char *str)
{
while (*str)
{
if (!isdigit(*str))
{
return (0);
}
str++;
}
return (1);
}

/**
 * main - Multiplies two positive numbers
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
unsigned long num1, num2, result;
if (argc != 3)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
return (98);
}
if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2]))
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
return (98);
}
num1 = strtoul(argv[1], NULL, 10);
num2 = strtoul(argv[2], NULL, 10);
result = num1 * num2;
unsigned long temp;
temp= result;
int num_digits = 0;
while (temp != 0)
{
temp /= 10;
num_digits++;
}
char buffer[12];
int i = num_digits;
while (i > 0)
{
buffer[i - 1] = result % 10 + '0';
result /= 10;
i--;
}
buffer[num_digits] = '\0';
i = 0;
while (buffer[i] != '\0')
{
_putchar(buffer[i]);
i++;
}
_putchar('\n');
return (0);
}
