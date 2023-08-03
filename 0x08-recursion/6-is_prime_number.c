#include "main.h"

/**
 * is_prime_helper - Helper function to check if the number is prime.
 * @n: The number to be checked for prime.
 * @i: The divisor to check for divisibility.
 *
 * Return: 1 if the number is prime, otherwise return 0.
 */
int is_prime_helper(int n, int i);

/**
 * is_prime_number - Returns 1 if the input integer is a prime number,
 * otherwise return 0.
 * @n: The number to be checked.
 * Return: 1 if the number is prime, otherwise return 0.
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);
return (is_prime_helper(n, 2));
}
int is_prime_helper(int n, int i)
{
if (i == n)
return (1);
if (n % i == 0)
return (0);
return (is_prime_helper(n, i + 1));
}
