#include <stdio.h>
#include "main.h"
void print_alphabet(void);
/**
* print_alphabet - prints the alphabet in lowercase, followed by a newline
*/
/* function definition */
void print_alphabet(void)
{
char c;
for (c = 'a'; c <= 'z'; c++)
{
putchar(c);
}
putchar('\n');
}
