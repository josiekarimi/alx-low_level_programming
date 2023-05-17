#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The number of arguments.
 * @av: Array of strings containing the arguments.
 *
 * Return: Pointer to the concatenated string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
char *concatenated;
int i, j, length, total_length = 0;
int index = 0;
if (ac == 0 || av == NULL)
return (NULL);
/* Calculate the total length of the arguments */
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
total_length++;
j++;
}
total_length++; /* Account for the '\n' character */
}
/* Allocate memory for the concatenated string */
concatenated = malloc((total_length + 1) * sizeof(char));
if (concatenated == NULL)
return (NULL);
/* Copy the arguments into the concatenated string */
for (i = 0; i < ac; i++)
{
j = 0;
length = 0;
while (av[i][j] != '\0')
{
concatenated[index] = av[i][j];
j++;
index++;
length++;
}
concatenated[index] = '\n';
index++;
}
concatenated[index] = '\0'; /* Add null-terminating character */
return (concatenated);
}
