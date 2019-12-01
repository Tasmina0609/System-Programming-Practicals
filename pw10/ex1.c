#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include<unistd.h>

void counter(int signal) {
  int count; count++;
  if (signal == SIGINT)
    printf("received SIGINT \n");
  if ( count == 5 ) exit(0);
}

int main() {
  printf("pid: %d\n",getpid());
  signal(SIGINT,counter);
  while(1);
  return 0;
}
