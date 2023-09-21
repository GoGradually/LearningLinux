#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *curPath = NULL;

    int fd;

    if (!(curPath = getcwd(NULL, BUFSIZ))) {
        perror("getcwd");
        exit(1);
    }
    printf("현재 디렉터리: %s\n", curPath);
    free(curPath);

    printf("bit 이렉터리 이동 시작...\n");

    if ((fd = open("bit", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }
    if (fchdir(fd) == -1) {
        perror("fchdir");
        exit(1);
    }
    if (!(curPath = getcwd(NULL, BUFSIZ))) {
        perror("getcwd");
        exit(1);
    }
    printf("현재 디렉터리: %s\n", curPath);

    free(curPath);
    close(fd);
}