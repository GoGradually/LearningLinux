#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("test.txt", O_CREAT|O_EXCL, 0644);
    if (fd == -1) {
        perror("Excl");
        exit(1);
    }
    close(fd);
}