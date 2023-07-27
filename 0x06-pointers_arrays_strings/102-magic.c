#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description:
 * This program demonstrates the "magic" challenge where we need to modify the
 * value of a[2] to 98 using a single line of code, adhering to certain constraints.
 * We utilize pointer arithmetic to accomplish this task.
 *
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
