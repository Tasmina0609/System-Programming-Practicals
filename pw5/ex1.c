#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main () {
      struct stat stbuf;
      // stat("foo.txt",&stbuf);   
      stat("../pw5",&stbuf);
    
      switch( (stbuf.st_mode & __S_IFMT) ) {
            case __S_IFREG: 
                  printf("File\n");      break;
            case __S_IFDIR:
                  printf("Directory\n"); break;
            default: 
                  printf("Invalid Type");
      }
      
    printf("File Permissions: (ls -l) \t");
    printf( (S_ISDIR(stbuf.st_mode)) ? "d" : "-");
    printf( (stbuf.st_mode & S_IRUSR) ? "r" : "-"     );
    printf( (stbuf.st_mode & S_IWUSR) ? "w" : "-"     );
    printf( (stbuf.st_mode & S_IXUSR) ? "x" : "-"     );
    printf( (stbuf.st_mode & S_IRGRP) ? "r" : "-"     );
    printf( (stbuf.st_mode & S_IWGRP) ? "w" : "-"     );
    printf( (stbuf.st_mode & S_IXGRP) ? "x" : "-"     );
    printf( (stbuf.st_mode & S_IROTH) ? "r" : "-"     );
    printf( (stbuf.st_mode & S_IWOTH) ? "w" : "-"     );
    printf( (stbuf.st_mode & S_IXOTH) ? "x" : "-"     );
    printf("\n\n");

      return 0;
}
