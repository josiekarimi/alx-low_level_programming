#include "main.h"

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: Pointer to the first element of the matrix.
 * @size: Size of the matrix.
 */
void print_diagsums(int *a, int size)
{
int i;
int sum1 = 0, sum2 = 0;

for (i = 0; i < size; i++)
{
sum1 += *(a + (size + 1) * i);
sum2 += *(a + (size - 1) * (i + 1));
}

/* Print the sum of the first diagonal */
print_number(sum1);

/* Print the comma and space separator */
print_char(',');

print_char(' ');
/* Print the sum of the second diagonal */
print_number(sum2);
/* Print a new line */
print_char('\n');
}

/**
 * print_number - Prints a number.
 * @n: The number to be printed.
 */
void print_number(int n)
{
int divisor = 1;
int i, num;


