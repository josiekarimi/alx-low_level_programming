#include <stdio.h>
#include "main.h"
/* function prototype */
void print_alphabet(void);
/**
* print_alphabet - prints the alphabet in lowercase, followed by a newline
*/
/* function definition */
void print_alphabet(void)
{
xchar c;
for (c = 'a'; c <= 'z'; c++)
{
putchar(c);
}
putchar('\n');
}

/* main function */
/**
* main - entry point of the program
*
* Return: Always 0 (Success)
*/
int main(void)
{
print_alphabet();
return (0);
}

