#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all the elements of list_t
 * @h: pointer to the head of the list_t
 *
 * Return: number of nodes in the list_t
 */
size_t print_list(const list_t *h)
{
size_t count = 0;
while (h != NULL)
{
if (h->str == NULL)
printf("[%u] (nil)\n", h->len);
else
printf("[%u] %s\n", h->len, h->str);
count++;
h = h->next;
}
return (count);
}

