#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * is_valid_number - Check if a string is a valid positive number.
 * @str: The string to check.
 * Return: true if valid, false otherwise.
 */
bool is_valid_number(const char *str)
{
while (*str)
{
if (!isdigit(*str))
{
return (false);
}
str++;
}
return (true);
}
int main(int argc, char *argv[])
{
int sum = 0;
int i;
if (argc == 1)
{
printf("0\n");
return (0);
}
for (i = 1; i < argc; i++)
{
if (!is_valid_number(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}
printf("%d\n", sum);
return (0);
}
