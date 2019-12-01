#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
void copy(int fdsrc, int fddst);

int main(int argc, char *argv[])  { 
  int n=3;
  int pid, nbytes;
  char readbytes[80], string[80];
  int pipes[n-1][2];
  for(int i=0;i<n-1;i++){//
    pipe(pipes[i]);
    pid=fork();
    if(pid!=0){//parent process
      //parent won't write, it reads and prints
      fprintf(stderr," parent %d\n", getpid());
      close(pipes[n-2][1]);
      nbytes=read(pipes[n-2][0], readbytes, 80);//read from last child
      write(1, readbytes, nbytes);//write to stdout
      close(pipes[n-2][0]);
    }
    else{//all child processes
      //get data from prev pipe
      //pass to the next pipe
      //if there is no prev, take from stdin
      fprintf(stderr,"child %d of a parent %d\n", getpid(), getppid());
      close(pipes[i][0]);
        if(i==0){
          nbytes=read(0, string, 80);//read from stdin
        }
        else{
          nbytes=read(pipes[i-1][0], string, 80);
        }
        write(pipes[i][1], string, nbytes);
        close(pipes[i][1]);
        exit(0);
    }
  }
  return(0);
}
/*
 void copy(int fdsrc, int fddst){
   int fd[2];//fd[0] - input fd[1]=output
   char readbytes[80];
   char string[80];
   int nbytes;
   pipe(fd);
   int pid=fork();
   if(pid==-1){
     perror("fork");
     exit(1);
   }
   else if(pid==0){
     //child -> read
     close(fd[1]);
     nbytes=read(fd[0], readbytes, 80);
     write(fddst, readbytes, nbytes);
     close(fd[0]);
     close(fddst);
   }
   else{
     // parent writes to pipe
     close(fd[0]);
     nbytes=read(fdsrc, string, 80);
     write(fd[1], string, nbytes);
     close(fd[1]);
     close(fdsrc);
   }
 }
*/
