#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ulimit.h>

void count(int signal) {
      static int count=0; printf("%d\n",count); 
      int pid=fork();
      if ( pid == -1 ) { exit(0); }
      else if ( pid == 0 ) {
            execlp("ulimit","ulimit","-c","unlimited",NULL);
            exit(0);
      }
      count++;
      if ( count >= 5 ) exit(0);
} 

int main() {

    printf("pid: %d\n", getpid());
    signal(SIGQUIT, count);
    while(1);

    return 0;
}

// void increment(int sig);

// int main(int argc, char *argv[]) {
//     printf("pid: %d\n", getpid());
//     signal(SIGQUIT, increment);
//     while(1);

//     return 0;
// }

// void increment(int sig) {
//     static int i = 0;
//     printf("%d\n", i++);
//     int pid = fork();
//     if (pid == -1) {
//         fprintf(stderr, "Error 1\n");
//         exit(1);
//     } else if (pid == 0) {
//         execlp("ulimit", "ulimit", "-c", "unlimited", (char*)0);
//         fprintf(stderr, "Error 2\n");
//         exit(2);
//     }
//     if (i >= 5) exit(0);
// }

