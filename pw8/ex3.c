#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/fcntl.h>

/* ps eaux > foo ; grep "^$1 " < foo > /dev/null && echo "$1 is connected" */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage %s username\n", argv[0]);
        exit(1);
    }

    int pid = fork();
      if ( pid == -1 ) { 
             fprintf(stderr, "Something went wrong\n");
              exit(-1);
      }
      else if ( pid == 0 ) { /* ps eaux > foo ; */
            int fd = open("foo", O_WRONLY | O_CREAT | O_TRUNC, 0666);
            dup2(fd, 1);
            close(fd);
            execlp("ps", "ps", "eaux", NULL);
            exit(2);
      }
      else {  /* grep "^$1 " < foo > /dev/null && echo "$1 is connected" */
            wait(NULL); 
            int pid1 = fork();
            if ( pid1 == -1 ) { exit(-1); }
            else if ( pid == 0 ) { /* grep "^$1 " < foo > /dev/null */
                  int fd1 = open("foo", O_RDONLY);
                  int fd2 = open("/dev/null", O_WRONLY | O_CREAT | O_TRUNC, 0666);

                  dup2(fd1, 0);
                  close(fd1);

                  dup2(fd2, 1);
                  close(fd2);

                  char *t=malloc(strlen(argv)+3);
                  sprintf(t,"^%s",argv[1]);
                  execlp("grep", "grep", t, NULL);
                  exit(3);
            }
            else { /* echo "$1 is connected" */
                wait(NULL);
                execlp("echo", "echo", argv[1], " is connected", NULL);
              }
      }
    return 0;
}