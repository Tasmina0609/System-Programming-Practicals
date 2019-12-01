#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

struct MYFILE{
      int FILE;
      char *buffer;
}; 

int my_open(char *filename,char *mode) {
      struct MYFILE mf;
    //  printf("%s\n",mode);
      if ( (mf.FILE=open(filename,O_RDONLY | O_WRONLY )) < 0 )   printf("Error in opening the file\n");
      else {
            if ( mode == "r" && (mf.FILE=open(filename,O_RDONLY)) )  {
             printf("%s opened for readable mode\n",filename);
             return 0;
            }
            else if ( mode == "w" &&   (mf.FILE=open(filename,O_WRONLY)) )  {
           //  printf("Opened for writable mode\n");
             return 1;
            }
      }
  //    printf("File exists");
}

char my_getc(char *filename) {
      struct MYFILE mf;
      mf.FILE=open(filename,O_RDONLY);
      int length;
      char buf;
      while ( (length = read(mf.FILE,&buf,100)) > 0 ) {
            //  printf("%d\n",length);
            // return c; 
            /* Displaying the characters read */
            length=write(1,&buf,length);
        }
      //  printf("%d\n",)
      close(mf.FILE);
}

char my_putc(char *filename) {
    struct MYFILE mf;
    char buf[128];
    mf.FILE = open(filename, O_WRONLY | O_APPEND);
    /* data to be written */
    scanf("%s", buf);
    write(mf.FILE, buf, strlen(buf)); 
    close(mf.FILE);
}

int my_close(char *filename) {
      struct MYFILE mf;
      close(mf.FILE);
}

int main() {
      struct MYFILE myfile;
      /* my open function */
      my_open("test.txt","r");

      /* my getc function */
      my_getc("test.txt");

      /* my putc function */
     printf("Enter what to be written to file: ");
     my_putc("test.txt");

      /* my close function */
      my_close("test.txt");

      printf("----------------------------\n");
      int fd1,fd2;
      fd1=my_open("foo1.txt","r");  // foo1.txt
      fd2=my_open("foo2.txt","r");  // foo2.txt

      my_getc("foo1.txt");
      my_getc("foo2.txt");

      return 0;
}