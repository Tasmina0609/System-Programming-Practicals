#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct month {
      char name[9+1] ;    /* month name */
      int days;  /* number of days in the month */
};

int main() {
    struct month months[12]={
          {"January", 31}, {"February", 28},{"March", 31}, 
          {"April", 30}, {"May", 31}, {"June", 30}, 
          {"July", 31}, {"August", 31}, {"September", 30},
          {"October", 31}, {"November", 30}, {"December", 31}
       };
    printf("Enter month: ");
    char m[15]; 
    scanf("%s",m);
    for(int i=0;i<12;i++) {
          if( strcmp(months[i].name,m) == 0 ) { // same
                printf("%d : ",i+1);
                printf("%s has %d days\n",months[i].name,months[i].days);
                exit(1);
          } 
    }
    printf("Incorrect Spelling or smth else\n");
    return 0;
}