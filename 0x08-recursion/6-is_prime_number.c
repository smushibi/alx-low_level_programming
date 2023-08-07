#include "main.h"

/**
 * is_prime_helper - Helper function to check if the number is prime.
 * @n: The number to be checked for prime.
 * @i: The divisor to check for divisibility.
 *
 * Return: 1 if the number is prime, otherwise return 0.
 *
 * is_prime_number - Check if the input integer is a prime number.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 *
 * Description: This function checks whether the input integer 'n'
 * is a prime number.
 * It returns 1 if 'n' is prime, and 0 otherwise. A number is
 *  prime if it
 * is greater than 1 and has no divisors other than 1 and itself.
 */

int is_prime_helper(int n, int i);
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
