#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * array_range - Creates an array of integers
 * @min: The minimum value (inclusive)
 * @max: The maximum value (inclusive)
 *
 * Return: Pointer to the newly created array
 *         NULL if min > max or if malloc fails
 */
int *array_range(int min, int max)
{
int *arr;
int size, i;
if (min > max)
return (NULL);
size = max - min + 1;
arr = malloc(size *sizeof(int));
if (arr == NULL)
return (NULL);
for (i = 0; i < size; i++)
arr[i] = min++;
return (arr);
}
