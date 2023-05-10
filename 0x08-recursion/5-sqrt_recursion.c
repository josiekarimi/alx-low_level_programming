#include "main.h"

/**
 * _sqrt_helper - Helper function to calculate the square root recursively
 * @n: The number to calculate the square root of
 * @guess: The current guess for the square root
 *
 * Return: The natural square root of the number
 */
int _sqrt_helper(int n, int guess);

/**
 * _sqrt_recursion - Calculates the natural square root of a number recursively
 * @n: The number to calculate the square root of
 *
 * Return: The natural square root of the number, or -1 if an error occurs
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
else if (n == 0 || n == 1)
return (n);
else
return (_sqrt_helper(n, 1));
}

/**
 * _sqrt_helper - Helper function to calculate the square root recursively
 * @n: The number to calculate the square root of
 * @guess: The current guess for the square root
 *
 * Return: The natural square root of the number
 */
int _sqrt_helper(int n, int guess)
{
if (guess * guess == n)
return (guess);
else if (guess * guess > n)
return (-1);
else
return (_sqrt_helper(n, guess + 1));
}

