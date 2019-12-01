#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
// find / -name "*.tex" > output >2 erreurs
int main(int argc,char *argv[]) {
      int pid=fork();
      int why;
      if ( pid == -1 ) { exit(20); }
      if ( pid == 0 ) { // child
            int fd1,fd2;
            fd1=open("output",O_CREAT | O_WRONLY,0666);
            fd2=open("error",O_CREAT | O_WRONLY,0666);
            printf("descriptors: %d %d\n",fd1,fd2);

            printf("Child exec...\n");
            dup2(fd1,1);  // output to stdout
            dup2(fd2,2);  // error to stderr ( print )

            execlp("find","find",".","-name","vip.tex",NULL);
            exit(0);
      }
      else { // parent
            printf("Parent launching a child\n");
            wait(&why);
            if ( WIFEXITED(why)) printf("exit code is %d\n", WEXITSTATUS(why));
      }
      return 0;
}

