#include "main.h"
#include <unistd.h>
/**
* _putchar - writes a character to stdout
* @c: the character to write to stdout
* Return: 1 on success, -1 on error
*/
int _putchar(char c)
{
if (write(1, &c, 1) == -1) /* check for error */
return (-1);
return (1);
}
