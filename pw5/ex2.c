#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
   // char dirname[] = "../pw1";
    char dirname[] = ".";  // current directory
    DIR *d = opendir(dirname);  // DIR - a type representing a directory stream.
    struct dirent *dir;  // It also defines the structure dirent 
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {  // no display of files starting with a dot
                printf("%s\t", dir->d_name);  // d->name == string array 
            }
        }
        printf("\n");
    } 
    else {
        printf("Cannot read %s directory\n", dirname);
    }

    return 0;
}
