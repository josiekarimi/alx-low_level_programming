/**
 * leet - encodes a string into 1337.
 * @s: The string to be encoded.
 *
 * Return: The encoded string.
 */
char *leet(char *s)
{
char *p = s;
char leet[5] = {'4', '3', '0', '7', '1'};
char letters[5] = {'a', 'e', 'o', 't', 'l'};
int i;
while (*p)
{
i = 0;
while (letters[i])
{
if (*p == letters[i] || *p == letters[i] - 32)
{
*p = leet[i];
break;
}
i++;
}
p++;
}
return (s);
}
