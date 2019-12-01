#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char *argv[]) {
      int res;
      struct stat sBuf;
      if ( argc !=2 ) {
            fprintf(stderr,"Usage: wrong number of arguments\n");
            exit(2);
      }
      printf("The file chosen: %s\n",argv[1]);
      res=stat(argv[1],&sBuf);
      if ( res != 0 ) {
            fprintf(stderr,"Error: no such file\n");
            exit(3);
      }
      printf("st_mtime: %ld\t st_ctime: %ld\tst_atime: %ld\n",sBuf.st_mtime,sBuf.st_ctime,sBuf.st_atime);  
      // st_atime: time of last access
      // st_mtime: time of last data modification
      // st_ctime: time of last file status change


      return 0;
}