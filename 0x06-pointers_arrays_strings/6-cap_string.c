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
int capitalize_next = 1;
while (str[index])
{
if (capitalize_next && isalpha(str[index]))
{
str[index] = toupper(str[index]);
capitalize_next = 0;
}
else if (isspace(str[index]) || ispunct(str[index]))
{
capitalize_next = 1;
}
index++;
}
return (str);
}
