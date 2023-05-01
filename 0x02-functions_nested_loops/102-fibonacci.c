#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int i;
int fib1 = 1;
int fib2 = 2;
int fib;
_putchar('0' + fib1);
_putchar(',');
_putchar(' ');
_putchar('0' + fib2);
for (i = 2; i < 50; i++)
{
fib = fib1 + fib2;
_putchar(',');
_putchar(' ');
printf("%d", fib);
fib1 = fib2;
fib2 = fib;
}
_putchar('\n');
return (0);
}
