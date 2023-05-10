#include "main.h"

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
int length = _strlen_recursion(s);
return (is_palindrome_helper(s, 0, length - 1));
}

/**
 * is_palindrome_helper - Helper function
 * @s: The string to check
 * @start: The starting index of the substring to check
 * @end: The ending index of the substring to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome_helper(char *s, int start, int end)
{
if (start >= end)
return (1);
if (s[start] != s[end])
return (0);
return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 * _strlen_recursion - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen_recursion(char *s)
{
if (*s == '\0')
return (0);
return (1 + _strlen_recursion(s + 1));
}
