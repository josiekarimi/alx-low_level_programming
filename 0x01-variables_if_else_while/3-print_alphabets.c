#include <stdio.h>
/**
* main - Prints all possible combinations of two two-digit numbers
*
* Return: Always 0
*/
int main(void)
{
int i;
for (i = 0; i < 26; i++)
putchar(i + 'a');
for (i = 0; i < 26; i++)
putchar(i + 'A');
putchar('\n');
return (0);
}
