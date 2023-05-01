#include <stdio.h>
#include "main.h"
#include <math.h>

/**
 * largest_factor - finds the largest factor of a given number
 * @n: the number to factorize
 *
 * Return: the largest factor of n that is also a prime number
 */
long largest_factor(long n)
{
long factor, max_factor;
factor = 2;
max_factor = 0;
while (n > 1)
{
if (n % factor == 0)
{
if (factor > max_factor)
max_factor = factor;
n /= factor;
}
else
{
factor++;
}
}
return (max_factor);
}
/**
 * main - entry point
 *
 * Return: Always 0
 */
int main(void)
{
long number, max_factor;
number = 612852475143;
max_factor = largest_factor(number);
printf("%ld\n", max_factor);
return (0);
}
