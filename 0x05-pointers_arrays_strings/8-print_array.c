#include <stdio.h>
#include "main.h"

/**
 * print_number - Prints a number
 * @n: The number to be printed
 */
void print_number(int n)
{
if (n < 0)
{
putchar('-');
n = -n;
}
if (n / 10)
print_number(n / 10);
/* Print the last digit */
putchar((n % 10) + '0');
}

/**
 * print_array - Prints n elements of an array of integers
 * @a: The input array
 * @n: The number of elements to be printed
 */
void print_array(int *a, int n)
{
int i;
for (i = 0; i < n; i++)
{
/* Print the current element */
if (a[i] < 0)
{
a[i] = -a[i];
putchar('-');
}
if (a[i] / 10)
print_number(a[i] / 10);
/* Print the last digit */
putchar((a[i] % 10) + '0');
/* Print a comma and a space if it's not the last element */
if (i != n - 1)
{
putchar(',');
putchar(' ');
}
}
/* Print a newline character */
putchar('\n');
}

