#include <stdio.h>
#include "main.h"
/**
* main - prints all possible different combinations of three digits
* Return: Always 0
*/x
/**
* print_alphabet - prints the alphabet in lowercase followed by a new line
*/
void print_alphabet(void)
{
char c = 'a';
while (c <= 'z')
{
putchar(c);
c++;
}
putchar('\n');
}
int main(void)
{
print_alphabet();
return (0);
}
