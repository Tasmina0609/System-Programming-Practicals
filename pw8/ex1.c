#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include <time.h>
#include<sys/time.h>
 #include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char *argv[]) {
      struct timeval tv1,tv2;

      if ( gettimeofday(&tv1, NULL) == 0 )  { // success , -1 failure
            printf("Seconds: %ld\n",tv1.tv_sec);  // seconds
            printf("Micro-seconds: %ld\n",tv1.tv_usec);  // micro-seconds 
      }

      if ( argc != 2 ) {
            printf("Usage: wrong number of arguments\n");
            exit(0);
      } 

      DIR *d;
      struct dirent *dir;
      d=opendir(argv[1]);
      if ( d == NULL ) {
          fprintf(stderr,"Directory can not be opened\n");
          exit(2);
       }
       
      int pid=fork();
      int why;
      switch(pid) {
            case -1:
                  fprintf(stderr,"Error\n");
                  exit(-1);
            case 0:
                  // printf("child : preparing to exec...\n");
                  execlp("ls","ls","-l",argv[1],NULL); 
                  exit(0);
            default:
                  // printf("parent : launching the child...\n");
                  wait(&why);
                  if(WIFEXITED(why)) printf("parent : exit code is %d\n", WEXITSTATUS(why));
                  gettimeofday(&tv2, NULL);
                  printf("Seconds: %ld \t\tMicro-seconds: %ld\n",tv2.tv_sec,tv2.tv_usec);  // sec + microsec
                  printf("\nInterval: %ld , %ld\n",tv2.tv_sec-tv1.tv_sec,tv2.tv_usec-tv1.tv_usec);
      }
        
      return 0;
}