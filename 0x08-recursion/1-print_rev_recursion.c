#include "main.h"
/**
 * _print_rev_recursion - Prints a string in reverse
 *  using recursion.
 * @s: Pointer to the string to be printed in reverse.
 *
 * Desc: Uses recursion to print a string in reverse order.
 *       Stops when it reaches the end of the string ('\0').
 */
void _print_rev_recursion(char *s)
{
if (*s == '\0')
{
return;
}
_print_rev_recursion(s + 1);
_putchar(*s);
}
