#include <stdio.h>
#include <string.h>
/**
 *  print_rev - Prints the reverse of a string to the standard output.
 * @s: A pointer to the string to be reversed and printed.
 */
void print_rev(char *s)
{
int i, j;
for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
{
char temp = s[i];
s[i] = s[j];
s[j] = temp;
}
}
