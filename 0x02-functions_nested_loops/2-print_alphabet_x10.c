#include <unistd.h>
/**
* _putchar - writes a character to stdout
* @c: the character to print
*
* Return: On success 1, on error -1 and errno set appropriately.
*/
int _putchar(char c)
{
return write(1, &c, 1);
}
/**
* print_alphabet_x10 - prints the alphabet in lowercase 10 times,
* followed by a new line
*/
/* function prototype */
void print_alphabet_x10(void)
{
char c;
int i;
for (i = 0; i < 10; i++)
{
for (c = 'a'; c <= 'z'; c++)
{
_putchar(c);
}
_putchar('\n');
}
}
/**
* main - entry point
*
* Return: always (0)
*/
int main(void)
{
print_alphabet_x10();
return (0);
}

