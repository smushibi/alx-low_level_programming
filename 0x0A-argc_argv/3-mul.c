#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 * Return: 0 on success, 1 on error or when receiving incorrect arguments.
 */
int main(int argc, char *argv[])
{
int num1;
int num2;
int product;
if (argc != 3)
{
printf("Error\n");
return (1);
}
num1 = atoi(argv[1]);
num2 = atoi(argv[2]);
product = num1 *num2;
printf("%d\n", product);
return (0);
}
