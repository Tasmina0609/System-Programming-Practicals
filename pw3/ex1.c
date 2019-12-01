#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

/*  USING ONLY SYSTEM CALLS */
int main(int args,char *ar[])  {
      int fd1=open("foo.txt",O_RDONLY);
      if ( fd1 == -1 ) {
            printf("Error in opening the file\n");  exit(0);
      }

      int fd2=open("bar.txt",O_CREAT | O_WRONLY ,0666);
      if ( fd2 == -1 ) {
            printf("Error in opening the file\n");  exit(0);
      }

      char buf[100];
      int k=0;
      while ( ( k=read(fd1,buf,100)) > 0 ) {
            write(fd2,buf,k);
      }

      close(fd1);
      close(fd2);
}