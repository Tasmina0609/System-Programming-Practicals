#include <stdio.h>
#include <stdlib.h>
int main() {
      FILE *aFile,*bFile;  // aFile - foo , bFile - bar 
      char c;
      aFile=fopen("foo","r");
      if ( aFile == NULL ) {
            fprintf(stderr,"Error in opening the file");
            exit(0);
      }
      bFile=fopen("bar","w");
       if ( bFile == NULL ) {
            fprintf(stderr,"Error in opening the file");
            exit(0);
      }
      c=getc(aFile);  // first charachter
    //  printf("%c\n",c);
      while ( c != EOF) {
            putc(c,bFile);
            c=getc(aFile);
      }
      printf("contents of file copied\n");
      fclose(aFile);
      fclose(bFile);
      return 0;
}

