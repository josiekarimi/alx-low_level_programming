#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the newly allocated memory containing the concatenated
 *         string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
char *concat;
unsigned int len1 = 0, len2 = 0, i, j;
/* Handle NULL strings as empty strings */
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
/* Calculate lengths of the strings */
while (s1[len1] != '\0')
len1++;
while (s2[len2] != '\0')
len2++;
/* Allocate memory for the concatenated string */
concat = malloc((len1 + len2 + 1) * sizeof(char));
if (concat == NULL)
return (NULL);
/* Copy characters from s1 to concat */
for (i = 0; i < len1; i++)
concat[i] = s1[i];
/* Copy characters from s2 to concat */
for (j = 0; j < len2; j++, i++)
concat[i] = s2[j];
/* Add null terminator */
concat[i] = '\0';
return (concat);
}
