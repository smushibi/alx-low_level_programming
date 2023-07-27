#include <ctype.h>
#include "main.h"
/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to be capitalized.
 *
 * Return: A pointer to the changed string.
 */
char *cap_string(char *str)
{
int index = 0;
while (str[index])
{
if (isalpha(str[index]))
{
if (index == 0 || !isalpha(str[index - 1]))
{
str[index] -= 32;
}
}
index++;
}
return (str);
}
