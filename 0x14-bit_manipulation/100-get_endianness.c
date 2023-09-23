#include "main.h"
#include <stdio.h>

/**
* get_endianness - Checks the endianness of the system.
*
* Return: 0 if big endian, 1 if little endian.
*/
int get_endianness(void)
{
unsigned int num;
char *endian;
num = 1;
endian = (char *)&num;
if (*endian == 1)
return (1);
else
return (0);
}
