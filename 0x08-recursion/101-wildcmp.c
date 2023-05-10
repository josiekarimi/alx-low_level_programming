#include "main.h"

/**
 * wildcmp - Compares two strings considering special character *
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: 1 if the strings are identical,
 */
int wildcmp(char *s1, char *s2)
{
if (*s2 == '*')
{
if (*(s2 + 1) == '\0') /* Check if * is at the end of s2 */
return (1);
else if (*s1 != '\0' && wildcmp(s1 + 1, s2)) /* Match * with a character */
return (1);
else
return (wildcmp(s1, s2 + 1)); /* Match * with an empty string */
}
else if (*s1 == *s2)
{
if (*s1 == '\0')
return (1);
else
return (wildcmp(s1 + 1, s2 + 1)); /* Recursively compare */
}
else
return (0);
}
