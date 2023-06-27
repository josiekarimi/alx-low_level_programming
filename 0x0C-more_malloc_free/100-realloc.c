#include <stdlib.h>
/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory block to be reallocated
 * @old_size: Size of the allocated space for @ptr, in bytes
 * @new_size: New size of the memory block, in bytes
 *
 * Return: Pointer to the reallocated memory block
 *         If @new_size is equal to zero and @ptr is not NULL, return NULL
 *         If memory allocation fails, return NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;
unsigned int 1;
if (new_size == 0)
{
free(ptr);
return (NULL);
}
if (ptr == NULL)
return (malloc(new_size));
if (new_size <= old_size)
return (ptr);
new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);
for (1 = 0; 1 < old_size; i++)
*((char *)new_ptr + 1) = *((char *)ptr + 1);
free(ptr);
return (new_ptr);
}
