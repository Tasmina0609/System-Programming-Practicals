#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// char *printSpecialCharachter(char *str) {
//     int len = strlen(str);
//     char *nstr=(char*)calloc(len*2,sizeof(char));
//     int count=0;

//     for(int i=0;i<len;i++) {
//            if ((str[i] > 31 && str[i] < 127) || str[i] == '\\') {
//             nstr[count++] = str[i];
//              } 
//          else {
//             if (str[i] == '\t') {
//                  nstr[count++] = '\\';  nstr[count++] = 't';
//             } else if (str[i] == '\n') {
//                  nstr[count++] = '\\';  nstr[count++] = 'n';
//             } else if (str[i] == '\r') {
//                  nstr[count++] = '\\';   nstr[count++] = 'r';
//             } else if (str[i] == '\b') {
//                 nstr[count++] = '\\';   nstr[count++] = 'b';
//             }
//          }
//     }
//      nstr[count] = '\0';
//     return nstr;
// }

int main(int argc, char *argv[]) {
    char str[100];
    printf("Enter string: ");
    fgets(str,100,stdin);

    int len = strlen(str);
    char *nstr=(char*)calloc(len*2,sizeof(char));
    int count=0;

    for(int i=0;i<len;i++) {
           if ((str[i] > 31 && str[i] < 127) || str[i] == '\\') {
            nstr[count++] = str[i];
             } 
         else {
            if (str[i] == '\t') {
                 nstr[count++] = '\\';  nstr[count++] = 't';
            } else if (str[i] == '\n') {
                 nstr[count++] = '\\';  nstr[count++] = 'n';
            } else if (str[i] == '\r') {
                 nstr[count++] = '\\';   nstr[count++] = 'r';
            } else if (str[i] == '\b') {
                nstr[count++] = '\\';   nstr[count++] = 'b';
            }
         }
    }
     nstr[count] = '\0';
      printf("%s",nstr);
      printf("\n");

    return 0;

}
