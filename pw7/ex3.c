#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[]) {
      if ( argc != 2 ) {
            printf("Wrong number of arguments\n");
            exit(1);
      } 

      int fd;  
      char c;
      fd=open(argv[1],O_RDONLY); // argv[1] = filename
      
      int pid=fork();
      if (pid == -1) {
         fprintf(stderr, "Error\n");
         exit(-1);
      }
      if ( pid == 0 ) {
            while( (read(fd,&c,1) > 0 )) {
                  printf("Child reads: [ %c ]\n",c);
                  sleep(1);
            }
      }
      else {
            while( (read(fd,&c,1) > 0 )) {
                  printf("Parent reads: [ %c ]\n",c);
                  sleep(1);
            }
      }

     /*** another way  parent and child 
      int n = 0;
      char c;
      while (1) {
        n = read(fd, &c, 1);
        if (n == 0) break;
        printf("%c", c);
      }
      ***/
     
      printf("\n");
      close(fd);
}