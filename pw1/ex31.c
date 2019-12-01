#include<stdio.h>
#include<string.h>
int read_line ( char line[] ,int size ) {
      int n,r;
      char *p;

      p=fgets(line,size,stdin);
      if ( p==NULL ) {
            r=EOF;
      }
      else {
            n=strlen(line);
            if ( n<0 && line[n-1] == '\n')
                  line[n-1];
                   r=EOF;
      }
}

int  main () {
      char line1[100],line2[100];
      unsigned char c;
      int i,j;

      (void) read_line(line1,sizeof line1);
      i=0; j=0;

      while ( (c=line1[i])!='\0') {
            if ( c< 32 || c>126 || c=='\'' ||  c=='\"' || c=='\\') {  // 32-126 symbols
                  line2[j++]='\\';   
                  switch(c) {
                        case '\n': line2[j++] ='n';break;  // n saved as       \ |  n 
                        case '\r': line2[j++] ='r';break;
                        case '\t': line2[j++] ='t';break;
                        case '\b': line2[j++] ='b';break;
                        case '\'': line2[j++] ='\'';break;
                        case '\"': line2[j++] ='\"';break;
                        case '\\': line2[j++] ='\\';break;
                        /* basic conversion to octal mode */
                        default: 
                            if ( c & 0700)
                               line2[j++]=((c&0700) >> (2*3))+'0';
                            if ( c & 0070)
                               line2[j++]=((c&0070)>> (1*3)) + '0';
                               line2[j++]=(c&0007)+'0';
                               break;
                        }
            }
            else line2[j++]=c;
            i++;
         }
      line2[j]='\0';
      puts(line2);
}