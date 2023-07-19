#include "main.h"
/**
 * print_alphabet_x10 - name oof the function
 * Description:  prints 10 times the alphabet, in lowercase,
 * Returns: returns (0)
 **/
void print_alphabet_x10(void)
{
int i;
char ch;
for (i = 0; i < 10; i++)
{
for (ch = 'a'; ch <= 'z'; ch++)
{
_putchar(ch);
}
_putchar('\n');
}
}
