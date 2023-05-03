#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
char *password = generate_password();
printf("Generated password: %s\n", password);
free(password);
return (0);
}
