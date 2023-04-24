#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
* main - Entry point of the program
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
else if (n < 0)
printf("negati
else
printf("zero\n");
return (0);
}
