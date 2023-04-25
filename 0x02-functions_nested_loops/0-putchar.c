#include <stdio.h>
/**
* main - entry point of the program
*
* Return: Always 0 (Success)
*/
int main(void)
{
char c[] = "_putchar\n";
int i;
for (i = 0; i < (int) sizeof(c) - 1; i++)
{
putchar(c[i]);
}
return (0);
}

