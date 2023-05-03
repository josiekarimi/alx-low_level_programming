#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generate_password(void);

/**
 * main - Entry point for the program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
srand(time(0));
char *password = generate_password();
printf("Generated password: %s\n", password);
free(password);
return (0);
}
/**
 * generate_password - Generates a random valid password for 101-crackme
 *
 * Return: Pointer to the generated password
 */
char *generate_password(void)
{
char *password = malloc(sizeof(char) * 100);
int i, length, type;
char c;
length = rand() % 10 + 6;
/* Password length between 6 and 15 */
i = 0;
while (i < length)
{
type = rand() % 3;
if (type == 0) /* Lowercase letter */
c = rand() % 26 + 'a';
else if (type == 1) /* Uppercase letter */
c = rand() % 26 + 'A';
else /* Digit */
c = rand() % 10 + '0';
password[i] = c;
i++;
}
password[i] = '\0';
return (password);
}

