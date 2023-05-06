#include "main.h"

/**
 * rot13 - Encodes a string using ROT13 cipher.
 * @s: The input string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *s)
{
char *ptr = s;
int i;
while (*ptr)
{
for (i = 0; (*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'); i++)
{
if ((*ptr >= 'a' && *ptr <= 'm') || (*ptr >= 'A' && *ptr <= 'M'))
*ptr += 13;
else
*ptr -= 13;
ptr++;
}
ptr++;
}
return (s);
}
