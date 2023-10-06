#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    struct stat statbuf;

    if (stat("test.ln", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("1. test.ln : link count : %d\n", (int)statbuf.st_nlink);

    if (unlink("test.ln") == -1) {
        perror("unlink");
        exit(1);
    }
    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("2. test.txt : link count : %d\n", (int)statbuf.st_nlink);
    unlink("test.sym");
}