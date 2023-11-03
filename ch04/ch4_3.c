#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;
    int mode;

    close(0);

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("Open");
        exit(1);
    }

    printf("test.txt : fd = %d\n", fd);
    close(fd);
}
