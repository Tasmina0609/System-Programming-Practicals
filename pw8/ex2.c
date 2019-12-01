#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<sys/times.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char *argv[]) {
      if ( argc != 2 ) {
            printf("Usage: wrong number of arguments\n");
            exit(0);
      } 

      int pid1=fork();
      int why;

      struct tms buf;
      int hz;

      switch(pid1) {
            case -1:
                  fprintf(stderr,"fork() error");
                  exit(-1);
            case 0:
                  execlp("ls","ls","-R",argv[1],NULL);
                  exit(0);
            default:
                  wait(&why);
                  if ( WIFEXITED(why) ) printf("exitcode %d\n",WEXITSTATUS(why));
                  if ( WIFSIGNALED(why) ) printf("stopped by signal %d",WTERMSIG(why));
                  
                  int pid2=fork();
                  switch(pid2) {
                   case -1:
                      fprintf(stderr,"fork() error");
                      exit(-1);
                   case 0:  /* "ls > /dev/null" */
                        int fd=open("/dev/null",O_CREAT | O_WRONLY,0666);
                        dup2(fd,1);
                        close(fd);
                        execlp("ls","ls",argv[1],NULL);
                        exit(0);
                   default:
                        wait(&why);
                   if ( WIFEXITED(why) ) printf("exitcode %d\n",WEXITSTATUS(why));
                   if ( WIFSIGNALED(why) ) printf("stopped by signal %d",WTERMSIG(why));
                   times(&buf);
                   hz=sysconf(_SC_CLK_TCK);
                   printf("Time spent: %f %f\n",(double)buf.tms_cutime/hz,(double)buf.tms_cstime/hz);
            }

      }  
      return 0;
}
