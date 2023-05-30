#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees the memory allocated for a dog
 * @d: Pointer to the dog to free
 *
 * Description: This function frees the memory allocated for a dog,
 *              including the memory allocated for its name and owner.
 */
void free_dog(dog_t *d)
{
if (d != NULL)
{
/* Free the memory allocated for name and owner */
free(d->name);
free(d->owner);
/* Free the memory allocated for the dog */
free(d);
}
}
