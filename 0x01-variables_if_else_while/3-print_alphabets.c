#include <stdio.h>x
int main() {
char lowercase = 'a';
char uppercase = 'A';
// print lowercase alphabet
while (lowercase <= 'z') {
putchar(lowercase);
lowercase++;
}
// print uppercase alphabet
while (uppercase <= 'Z') {
putchar(uppercase);
uppercase++;
}
// print newline
putchar('\n');
return 0;
}
