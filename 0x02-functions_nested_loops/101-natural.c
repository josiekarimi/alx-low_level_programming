#include "main.h"

/**
 * main - Computes and prints the sum of all the multiples.
 *
 * Return: Always 0.
 */
int main(void)
{
int i, sum;
sum = 0;
for (i = 0; i < 1024; i++)
{
if (i % 3 == 0 || i % 5 == 0)
sum += i;
}
_putchar(sum / 10 + '0');
_putchar(sum % 10 + '0');
_putchar('\n');
return (0);
}
