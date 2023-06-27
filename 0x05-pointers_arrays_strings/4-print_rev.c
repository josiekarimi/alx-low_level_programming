#include <stdio.h>
#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line.
 * @s: The string to be printed.
 *
 * Return: void.
 */
int _putchar(char c)
{
return write(1, &c, 1);
}
void print_rev(char *s)
{
int len = 0, i;
while (s[len] != '\0')
len++;
for (i = len - 1; i >= 0; i--)
_putchar(s[i]);
_putchar('\n');
}


