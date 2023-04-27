#include "main.h"

/**
 * fizz_buzz - Prints numbers from 1 to 100, with FizzBuzz rules
 *
 * Return: void
 */
void fizz_buzz(void)
{
int i;
for (i = 1; i <= 100; i++)
{
if (i % 3 == 0 && i % 5 == 0)
{
_putchar('F');
_putchar('i');
_putchar('z');
_putchar('z');
_putchar('B');
_putchar('u');
_putchar('z');
_putchar('z');
}
else if (i % 3 == 0)
{
_putchar('F');
_putchar('i');
_putchar('z');
_putchar('z');
}
else if (i % 5 == 0)
{
_putchar('B');
_putchar('u');
_putchar('z');
_putchar('z');
}
else
{
int num = i;
int digits = 1;
int divisor = 1;
while (num > 0)
{
digits++;
divisor *= 10;
num /= 10;
}
divisor /= 10;
while (divisor >= 1)
{
int digit = (i / divisor) % 10;
_putchar(digit + '0');
divisor /= 10;
}
}
if (i < 100)
_putchar(' ');
}
_putchar('\n');
}
