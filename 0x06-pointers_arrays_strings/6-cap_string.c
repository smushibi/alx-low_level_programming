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
int is_word_start = 1;
while (str[index])
{
if (isalpha(str[index]) || str[index] == '_')
{
if (is_word_start)
{
str[index] -= 32;
}
is_word_start = 0;
}
else
{
is_word_start = 1;
}
index++;
}
return (str);
}
