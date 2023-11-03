#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    struct stat statbuf;

    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    if ((statbuf.st_mode & S_IFMT) == S_IFREG) printf("test.txt : 정규 파일\n");
    if (S_ISREG(statbuf.st_mode)) printf("test.txt : 정규 파일\n");
}