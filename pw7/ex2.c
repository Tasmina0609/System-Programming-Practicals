#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/*  launch n child processes */
int main() {
      int n;
      printf("Enter n: ");  scanf("%d",&n);
      
      int pid; 
      int why;
      for(int i=0;i<n;i++) {  /* for n-child procceses */
            pid=fork();
            if ( pid == -1 ) {
                  fprintf(stderr,"Error\n");  exit(-1);
            }
            if ( pid == 0)  {
                  printf("Child (%d) : %d\t",i,getpid());
                  exit(i);  /* if you don't -> mnogo parents */
            }
            else {
                  wait(&why); /* child to terminate */
                  printf("Parent : %d\t",getpid());
                  if (WIFEXITED(why)) printf("Return value: %d\n", WEXITSTATUS(why));
            }
      }

}