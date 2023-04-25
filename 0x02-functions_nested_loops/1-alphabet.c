#include "main.h"x
/**
* print_alphabet - prints the alphabet in lowercase, followed by a new line.
*/
void print_alphabet(void)
{
char c;
for (c = 'a'; c <= 'z'; c++)
_putchar(c);
_putchar('\n');
}
/**
* main - check the code
*
* Return: Always 0.
*/
int main(void)
{
print_alphabet();
return (0);
}

