#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 if s1 and s2 are equal, less than 0 if s1 is less than s2,
 *         greater than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
int i;
for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
if (s1[i] == s2[i])
return (0);
else if (s1[i] == '\0')
return (-1);
else
return (1);
}
