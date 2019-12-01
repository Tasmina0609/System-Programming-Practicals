#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>
#include <unistd.h>

int x =0 ;

void handle_sigint(int sig) {
  int fd=open("file.txt", O_CREAT|O_WRONLY, 0666);
  if(x==4) exit(0);
  if(sig==SIGINT){
        char c[20];
        sprintf(c,"%c",x);
        printf("%c\n",c[2]);
        write(fd, &c, sizeof(c));
        printf("caught signal %d, counter is %d\n", sig, x++);
  }
    // if(sig==15){exit(0);}
    // x++;
    // printf("\nCaught signal %d, counter is %d \n", sig,x);
}

int main(){
    // signal(SIGINT, handle_sigint);
    // signal(SIGTERM, handle_sigint);
  struct sigaction s;
   s.sa_handler = handle_sigint;
   s.sa_flags = 0;
	sigemptyset(&s.sa_mask);
	sigaction(SIGINT,&s,NULL);
	sigaction(SIGTERM,&s,NULL);
  while (1) ;
  return 0;
}