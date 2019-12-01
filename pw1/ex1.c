#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
      // reads a string from the stdin using fgets
      printf("String : ");
      char str1[20];
      fgets(str1,sizeof(str1),stdin);  
      puts(str1);

      // strcpy into another string
      char str2[20];
      strncpy(str2,str1,sizeof(str2));  
      printf("Duplicate string: ");    puts(str2);        // puts used

      // strlen for length
      strtok(str2,"\n");  // strtok - to retrieve accurate length
      printf("strlen(duplicate): %d\n",(int)strlen(str2));
      return 0;
}