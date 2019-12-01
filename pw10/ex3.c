#include<stdio.h>
#include<stdlib.h>
 #include <unistd.h>
#include<signal.h>

void getsignal(int signal) {
      char buffer[100];
      psignal(signal,buffer);  // prints the descr of signal
    //  printf("%s\n",buffer);
      exit(0);
}

int main() {
      printf("pid: %d\n",getpid());
      signal(SIGINT,getsignal);
      // signal(SIGHUP, display_sig);
    // signal(SIGINT, display_sig);
    // signal(SIGQUIT, display_sig);
    // signal(SIGILL, display_sig);
    // signal(SIGABRT, getsignal);
    // signal(SIGFPE, display_sig);
    // signal(SIGKILL, display_sig);
    // signal(SIGSEGV, display_sig);
    // signal(SIGPIPE, display_sig);
    // signal(SIGALRM, display_sig);
    // signal(SIGTERM, display_sig);
    // signal(SIGUSR1, display_sig);
    // signal(SIGUSR2, display_sig);
    // signal(SIGCHLD, display_sig);
    // signal(SIGCONT, display_sig);
    // signal(SIGSTOP, display_sig);
    // signal(SIGTSTP, display_sig);
    // signal(SIGTTIN, display_sig);
    // signal(SIGTTOU, display_sig);

    while(1);
}