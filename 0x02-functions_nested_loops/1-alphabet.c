#include "main.h"
/**
 * print_alphabet - Prints all alphabets in lowercase.
 * Description: This function prints all the lowercase alphabets from 'a' to 'z'.
 */
void print_alphabet(void)
{
char letter;
for (letter = 'a'; letter <= 'z'; letter++)
putchar(letter);
putchar('\n');
}
