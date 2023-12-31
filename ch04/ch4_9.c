#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd, flags;

    fd = open("linux.txt", O_RDWR);
    if (fd == -1) {
        perror("Open");
        exit(1);
    }
    if ((flags = fcntl(fd, F_GETFL)) == -1) {
        perror("fcntl");
        exit(1);
    }

    flags |= O_APPEND;

    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl");
        exit(1);
    }
    if (write(fd, "Hanbit Academy\n", 15) != 15) perror("write");
    close(fd);
}