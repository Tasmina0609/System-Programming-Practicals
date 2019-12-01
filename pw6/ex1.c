#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <dirent.h>
// char *getenv(const char *name);

int main() {
      printf("PATH: %s\n",getenv("PATH"));
      printf("\n");

      /* splits the PATH */
      char *buffer=getenv("PATH");  
      char *s=":";
      char *token=strtok(buffer,s);
      int length=strlen(buffer)+1;
      char *array[20];

      int i=0;
      while ( token != NULL ) {
            // printf("%s\n",token);
             array[i]=token;  // po odnomu zapisivayu v array
             token=strtok(NULL,s); 
             i++;
      }

      for(int i=0;i<19;i++) {
             printf("%s\n",array[i]);
      }

      char *command="snap";
      int count = 0;
      while ( count < length ) {
           DIR *d = opendir(array[count]);
           struct dirent *dir;
          if (d!=NULL) {
             while ((dir = readdir(d)) != NULL) {
                  if (!strcmp(dir->d_name, command)) {
                     printf("\n%s is found in %s\n", command, array[count]);
                     exit(0);
                }
            }
           closedir(d);
             }
        ++count;
     }
      
    return 0;
}
