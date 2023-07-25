#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Generates a random password and prints it.
 * Return: Always 0 (indicating success)
 */
int main(void)
{
int i;
char password[10];
srand(time(NULL));
for (i = 0; i < 10; i++)
{
password[i] = rand() % 128;
}
printf("%s\n", password);
return (0);
}
