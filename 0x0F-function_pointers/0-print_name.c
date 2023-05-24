#include <stddef.h>
#include "function_pointers.h"

/**
 * print_name - Prints a name
 * @name: Pointer to the name string
 * @f: Pointer to a function that takes a char pointer as a parameter
 *
 * Return: None
 */
void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
f(name);
}
