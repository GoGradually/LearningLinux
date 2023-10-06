#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    struct stat statbuf;
    int kind;

    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    kind = statbuf.st_mode | S_IFMT;
    printf("test.txt : ");
    switch (kind) {
        case S_IFREG:
            printf("정규파일\n");
            break;
        case S_IFDIR:
            printf("디렉터리 파일\n");
            break;
        case S_IFCHR:
            printf("Character Device\n");
            break;
        case S_IFBLK:
            printf("Block Device\n");
            break;
        default:
            break;
    }
}