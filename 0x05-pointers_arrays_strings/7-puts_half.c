#include <stdio.h>
#include "main.h"

/**
 * puts_half - Prints half of a string
 * @str: The input string
 */
void puts_half(char *str)
{
int length = 0, i, n;
/* Calculate the length of the string */
while (str[length] != '\0')
length++;
/* Calculate the number of characters to print */
n = (length + 1) / 2;
/* Print the second half of the string */
for (i = n; i < length; i++)
putchar(str[i]);
/* Print a newline character */
_putchar('\n');
}
