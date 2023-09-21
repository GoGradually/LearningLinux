#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *curPath;

    if (!(curPath = getcwd(NULL, BUFSIZ))) {
        perror("getcwd");
        exit(1);
    }
    printf("현재 디렉터리: %s\n", curPath);
    free(curPath);

    printf("bit 이렉터리 이동 시작...\n");

    if (chdir("bit") == -1) {
        perror("chdir");
        exit(1);
    }

    if (!(curPath = getcwd(NULL, BUFSIZ))) {
        perror("getcwd");
        exit(1);
    }
    printf("현재 디렉터리: %s\n", curPath);
    free(curPath);
}