#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
* main - Entry point of the program
*
* Return: Always 0
*/
int main(void)
{
int n;

srand(time(NULL));
n = rand() - RAND_MAX / 2;

printf("%d is ", n);

if (n > 0)
printf("positive\n");
else if (n == 0)
printf("zero\n");
else
printf("negative\n");
return (0);
}
