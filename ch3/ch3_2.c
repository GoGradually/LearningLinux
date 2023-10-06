#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;
    struct stat statbuf;

    fd = open("linux.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    if (fstat(fd, &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("Inode = %lu\n", (int)statbuf.st_ino);
    printf("UID = %d\n", (int)statbuf.st_uid);

    close(fd);
}