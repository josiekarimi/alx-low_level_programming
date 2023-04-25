#include <stdio.h>
#include "main.h"

/**
* print_alphabet - Prints the lowercase alphabet using _putchar
*/
void print_alphabet(void)
{
char c = 'a';
while (c <= 'z')
{
_putchar(c);
c++;
}
_putchar('\n');
}

