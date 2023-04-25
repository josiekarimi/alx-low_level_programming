#include <stdio.h>
/* function prototype */
void print_alphabet(void);
/* main function */
/**
* main - entry point of the program
*
* Return: Always 0 (Success)
*/
int main(void)
{
print_alphabet();
/**
* print_alphabet - prints the alphabet in lowercase, followed by a newline
*/
return (0);
}
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

