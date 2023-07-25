#include <stdio.h>
#include "main.h"
/**
 * _puts - Prints a string to the standard output.
 * @str: A pointer to the string to be printed.
 */
void _puts(char *str)
{
if (str[0] != '\0')
{
printf("%s\n", str);
}
}
