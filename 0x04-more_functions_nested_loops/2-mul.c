#include "main.h"

/**
* mul - Multiplies two integers
* @a: The first integer to be multiplied
* @b: The second integer to be multiplied
*
* Return: The result of the multiplication
*/
int mul(int a, int b)
{
int result = 0;
while (b > 0)
{
if (b & 1)
result += a;
a <<= 1;
b >>= 1;
}
return result;
}
