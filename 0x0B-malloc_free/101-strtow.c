#include "main.h"
#include <stdlib.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words)
 */
char **strtow(char *str)
{
char **words;
int i, j, k, word_count = 0, len = 0, start_index = 0, word_length = 0;
if (str == NULL || *str == '\0')
return (NULL);
/* Count the number of words */
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] == ' ')
continue;
if (i == 0 || str[i - 1] == ' ')
word_count++;
}
words = malloc((word_count + 1) * sizeof(char *));
if (words == NULL)
return (NULL);
/* Extract and store each word */
for (i = 0, j = 0; str[i] != '\0' && j < word_count; i++)
{
if (str[i] == ' ')
continue;
if (i == 0 || str[i - 1] == ' ')
start_index = i;
if (i > 0 && str[i - 1] != ' ')
len++;
if ((i > 0 && str[i - 1] != ' ' && str[i] == ' ') || (str[i] != ' ' && str[i + 1] == '\0'))
{
word_length = len;
len = 0;
words[j] = malloc((word_length + 1) * sizeof(char));
if (words[j] == NULL)
{
/* Free memory allocated so far */
for (k = 0; k < j; k++)
free(words[k]);
free(words);
return (NULL);
}
for (k = 0; k < word_length; k++)
words[j][k] = str[start_index++];
words[j][k] = '\0';
j++;
}
}
words[word_count] = NULL;
return (words);
}
