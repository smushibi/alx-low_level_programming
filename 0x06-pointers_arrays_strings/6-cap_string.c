#include <ctype.h>
#include <string.h>
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
int is_word_start = 1;
char separators[] = " \t\n,;.!?\"(){}_";
while (str[index])
{
if (strchr(separators, str[index]))
{
is_word_start = 1;
}
else if (isalpha(str[index]) || str[index] == '_')
{
if (is_word_start)
{
str[index] -= 32;
}
is_word_start = 0;
}
index++;
}
return (str);
}
