#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
 //  ps eaux | grep "<name>" | wc -l
    int tube1[2];

    if (pipe(tube1) != 0) {
        fprintf(stderr, "Cannot pipe(1)\n");
        exit(1);
    }

    int pid1 = fork();

    if (pid1 == -1) {
        fprintf(stderr, "Cannot fork(1)\n");
        exit(2);
    } else if (pid1 == 0) {
        int tube2[2];

        if (pipe(tube2) != 0) {
            fprintf(stderr, "Cannot pipe(1)\n");
            exit(3);
        }

        int pid2 = fork();

        if (pid2 == -1) {
            fprintf(stderr, "Cannot fork(2)\n");
            exit(4);
        } else if (pid2 == 0) { // ps eaux
            close(tube2[0]);
            dup2(tube2[1], 1);
            close(tube2[1]);
            execlp("ps", "ps", "eaux", (char*)0);
            fprintf(stderr, "Cannot execlp(1)\n");
            exit(5);
        }
        // grep $USER
        close(tube2[1]);
        dup2(tube2[0], 0);
        close(tube2[0]);

        dup2(tube1[1], 1);
        close(tube1[1]);
        execlp("grep", "grep", (argc == 2) ? argv[1] : getenv("USER"), (char*)0);
        fprintf(stderr, "Cannot execlp(2)\n");
        exit(6);
    }
    // "wc -l"
    close(tube1[1]);
    dup2(tube1[0], 0);
    close(tube1[0]);
    execlp("wc", "wc", "-l", (char*)0);
    fprintf(stderr, "Cannot execlp(3)\n");

    return 6;
}