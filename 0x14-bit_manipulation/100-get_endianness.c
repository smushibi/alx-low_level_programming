/**
* get_endianness - Checks the endianness of the system.
*
* Return: 0 if big endian, 1 if little endian.
*/
int get_endianness(void)
{
union
{
unsigned int i;
char c[sizeof(unsigned int)];
} test;

test.i = 1;

return (test.c[0] == 1);
}
