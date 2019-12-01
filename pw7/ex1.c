#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* generate a child process using the system call fork */
int main () {
      int pid=fork();  /* child process generated  */
      int why;
      switch(pid) {
         case -1: /* unsuccesful creation of process */
              perror("fork() error");
              exit(-1);
         case 0:  /* child process */
              printf("child %d: parent %d\n",getpid(),getppid());
              exit(getpid()%10);
         default:  /* parent process (>0) */
              printf("parent %d: child %d\n",getpid(),pid);
              wait(&why);  /* waiting for child process to terminate */
              // printf("Return code: %d\n", wait(&why));
              if ( WIFEXITED(why) ) printf("exitcode %d\n",WEXITSTATUS(why));
              if ( WIFSIGNALED(why) ) printf("stopped by signal %d",WTERMSIG(why));
       }
      return 0;
}
