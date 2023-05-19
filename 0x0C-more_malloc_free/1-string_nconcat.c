#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes of s2 to concatenate
 *
 * Return: A pointer to the concatenated string
 *         If the function fails, it returns NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *concatenated;
unsigned int len1 = 0, len2 = 0, i, j;
if (s1 != NULL)
{
for (len1 = 0; s1[len1] != '\0'; len1++)
;
}
if (s2 != NULL)
{
for (len2 = 0; s2[len2] != '\0'; len2++)
;
}
if (n >= len2)
n = len2;
concatenated = malloc(sizeof(char) * (len1 + n + 1));
if (concatenated == NULL)
	return (NULL);
for (i = 0; i < len1; i++)
concatenated[i] = s1[i];
for (j = 0; j < n; j++)
concatenated[i + j] = s2[j];
concatenated[i + j] = '\0';
return (concatenated);
}
