#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

char *my_ttyname(int fd) {
    struct stat st;
    fstat(fd, &st);  // info about a file
    
    DIR *d = opendir("/dev/pts/"); 
    struct dirent *dir;

    if ( d == NULL ) {
          fprintf(stderr,"Directory does not exist\n");
          exit(2);
    }
    else { 
        while ( (dir = readdir(d)) != NULL) {
            if ( dir->d_ino == st.st_ino ) {
                char *name = (char*) calloc(15, sizeof(char));
                strcpy(name , "/dev/pts/");
                strcat(name , dir->d_name);
                return name;
            }
        }
    }
}

int main() {
       printf("%s\n", my_ttyname(STDIN_FILENO));   // 0 
       printf("%s\n", my_ttyname(STDOUT_FILENO));  // 1
       printf("%s\n", my_ttyname(STDERR_FILENO));  // 2
      return 0;
}
