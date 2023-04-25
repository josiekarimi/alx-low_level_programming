#include <stdio.h>
#include "main.h"
/**
* main - entry point of the program
*
* Return: Always 0 (Success)
*/
int main(void)
{
char c[] = "_putchar\n";
for (int i = 0; i < sizeof(c); i++)
{
putchar(c[i]);
}
return (0);
}


