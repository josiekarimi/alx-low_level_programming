#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the contents of a struct dog
 * @d: Pointer to the struct dog variable to print
 *
 * Description: This function prints the contents of a struct dog variable,
 *              including the name, age, and owner.
 *              If any element of the struct dog is NULL, it prints (nil)
 *              instead of that element.
 *              If d is NULL, it prints nothing.
 */
void print_dog(struct dog *d)
{
if (d != NULL)
{
printf("Name: %s\n", d->name != NULL ? d->name : "(nil)");
printf("Age: %.1f\n", d->age);
printf("Owner: %s\n", d->owner != NULL ? d->owner : "(nil)");
}
}
