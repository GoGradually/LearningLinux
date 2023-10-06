#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    struct stat statbuf;

    stat("linux.txt", &statbuf);

    printf("Inode = %d\n", (int)statbuf.st_ino);
    printf("Mode = %o\n", (int)statbuf.st_mode);
    printf("Nlink = %o\n", (int)statbuf.st_nlink);
    printf("UID = %d\n", (int)statbuf.st_uid);
    printf("GID = %d\n", (int)statbuf.st_gid);
    printf("SIZE = %d\n", (int)statbuf.st_size);
    printf("Blksize = %d\n", (int)statbuf.st_blksize);
    printf("Blocks = %d\n", (int)statbuf.st_blocks);

    printf("** timespec Style\n");
    printf("Atime: %ld\n", statbuf.st_atime);
    printf("Mtime: %ld\n", statbuf.st_mtime);
    printf("Ctime: %ld\n", statbuf.st_ctime);
}