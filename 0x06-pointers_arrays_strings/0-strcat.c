#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 *
 * Return: Pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
int dest_len = 0, i;
/* Find the length of the destination string */
while (dest[dest_len] != '\0')
{
dest_len++;
}
/* Append the source string to the destination string */
for (i = 0; src[i] != '\0'; i++)
{
dest[dest_len + i] = src[i];
}
/* Add the terminating null byte */
dest[dest_len + i] = '\0';
/* Return the pointer to the destination string */
return (dest);
}
