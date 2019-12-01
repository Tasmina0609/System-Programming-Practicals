#include <stdio.h>

/* BUFFERIZED VERSION OF GETC */
char buffer[100];

char my_getchar() {
   int i=0;
   return (buffer[i++] = getc(stdin));
}

int main() {
      printf("one charachter: ");
      printf("%c\n", my_getchar());
}