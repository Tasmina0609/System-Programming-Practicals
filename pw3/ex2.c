#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* RETURNS THE CHAR READ FROM stdin */
char my_getchar() {
    return getc(stdin);
}

int main() {
    printf("Enter one character: ");
  //  printf("%c\n",my_getchar());
    getc(stdin);
    return(0);
}

 