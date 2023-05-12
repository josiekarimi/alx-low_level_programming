#include "main.h"
#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: The number of command line arguments
 * @argv: An array of strings containing the command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
int count = argc - 1;
(void)argv; /* Unused parameter */
printf("%d\n", count);
return (0);
}
