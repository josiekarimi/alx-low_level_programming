#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array and initializes it with zeros
 * @nmemb: The number of elements in the array
 * @size: The size of each element
 *
 * Return: A pointer to the allocated memory
 *         If nmemb or size is 0, returns NULL
 *         If malloc fails, returns NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
unsigned int total_size;
unsigned int i;
if (nmemb == 0 || size == 0)
return (NULL);
total_size = nmemb * size;
ptr = malloc(total_size);
if (ptr == NULL)
return (NULL);
/* Set the allocated memory to zero */
for (i = 0; i < total_size; i++)
*((char *)ptr + i) = 0;
return (ptr);
}

