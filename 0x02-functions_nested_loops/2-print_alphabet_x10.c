#include <unistd.h>

int _putchar(char c)
{
return write(1, &c, 1);
}
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
int main(void)
{
print_alphabet_x10();
return (0);
}

