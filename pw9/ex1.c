#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void copy(int fdsrc,int fddst) {
      int length;
      char c;
      while((length=read(fdsrc,&c,1)) > 0 ) {
            write(fddst,&c,1);
      }
}

int main(int argc, char *argv[])  {

      int tube[2];
      if ( pipe(tube) != 0 ) {
            fprintf(stderr,"Pipe failed\n");
            exit(1);
      }
      
      int pid=fork();
      if ( pid == -1 ) {
            fprintf(stderr,"Error\n");
            exit(-1);
      }
      if ( pid == 0 ) {  // child writes to stdout
            close(tube[1]);
            copy(tube[0],1);
            close(tube[0]);
            exit(0);
      }
      else {  // parent reads from stdin
            close(tube[0]);
            copy(0, tube[1]);
            close(tube[1]);
      }

      return 0;
}
