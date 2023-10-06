#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    struct stat statbuf;

    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("test.txt -> hard link count : %d\n", (int)statbuf.st_nlink);

    printf("하드 링크 생성하기..\n");

    if (link("test.txt", "test.ln") == -1) {
        perror("link");
        exit(1);
    }

    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("test.txt -> hard link count : %d\n", (int)statbuf.st_nlink);
}