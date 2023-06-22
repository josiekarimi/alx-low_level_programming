#include "main.h"
#include <stdio.h>

#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
unsigned long int mask = 1;
int i, len;
len = sizeof(unsigned long int) * 8;
/* Find the most significant bit */
for (i = len - 1; i >= 0; i--)
{
if ((n >> i) & 1)
break;
}
/* Print the binary representation */
for (; i >= 0; i--)
{
mask = 1UL << i;
putchar((n & mask) ? '1' : '0');
}
}

