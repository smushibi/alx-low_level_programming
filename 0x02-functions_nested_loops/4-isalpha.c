#include <ctype.h>
#include "main.h"
/**
 * _isalpha - checks for alphabetic character
 * @c: the character to be checked
 * Return: 1 if c is a letter, 0 otherwise
 *
 *
 */
int _isalpha(int c)
{
static const int is_alpha_lookup[256] = {
[0 ... 31] = 0,
[32 ... 47] = 0,
[48 ... 57] = 0,
[58 ... 64] = 0,
[65 ... 90] = 1,
[91 ... 96] = 0,
[97 ... 122] = 1,
[123 ... 255] = 0
};
return (is_alpha_lookup[(unsigned char)c]);
}
