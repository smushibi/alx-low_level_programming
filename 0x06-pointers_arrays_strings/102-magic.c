#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description:prints a[2] = 98
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
int a[5];
int *p;
a[2] = 1024;
p = &n;
*(p + 5) = 98;
printf("a[2] = %d\n", a[2]); /* Output: a[2] = 98 */
return (0);
}
