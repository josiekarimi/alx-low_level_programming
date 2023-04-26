#include "main.h"

/**
 * times_table - Prints the 9 times table
 */
void times_table(void)
{
int row, col, res;
for (row = 0; row <= 9; row++)
{
_putchar('0');
for (col = 1; col <= 9; col++)
{
res = row * col;
_putchar(',');
_putchar(' ');
if (res < 10)
_putchar(' ');
else
_putchar(res / 10 + '0');
_putchar(res % 10 + '0');
}
_putchar('\n');
}
}
