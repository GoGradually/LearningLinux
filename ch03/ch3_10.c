#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    struct stat statbuf;
    printf("1. stat : test.txt .. \n");
    stat("test.txt", &statbuf);
    printf("test.txt -> link count : %d\n", (int)statbuf.st_nlink);
    printf("test.txt -> Inode : %d\n\n", (int)statbuf.st_ino);

    printf("2. stat : test.sym .. \n");
    stat("test.sym", &statbuf);
    printf("test.sym -> link count : %d\n", (int)statbuf.st_nlink);
    printf("test.sym -> Inode : %d\n\n", (int)statbuf.st_ino);

    printf("3. lstat : test.sym .. \n");
    lstat("test.sym", &statbuf);
    printf("test.sym -> link count : %d\n", (int)statbuf.st_nlink);
    printf("test.sym -> Inode : %d\n\n", (int)statbuf.st_ino);
}