#include "main.h"

/**
 * rev_string - Reverses a string in place.
 * @s: The string to be reversed.
 *
 * Return: void.
 */
void rev_string(char *s)
{
int i, j;
char tmp;
for (i = 0, j = 0; s[j + 1] != '\0'; j++)
;
while (i < j)
{
tmp = s[i];
s[i] = s[j];
s[j] = tmp;
i++;
j--;
}
}

