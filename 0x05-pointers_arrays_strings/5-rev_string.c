#include "main.h"
/**
 * rev_string - Reverses a string
 * @s: Input string
 * Return: String in reverse
 */
void rev_string(char *s)
{
char rev;
int i, j;
for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
{
rev = s[i];
s[i] = s[j];
s[j] = rev;
}
}
