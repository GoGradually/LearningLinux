#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    struct stat statbuf;

    printf("변경전 권한 출력하기: ");
    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("%o\n", statbuf.st_mode);

    if (chmod("test.txt", S_IRWXU | S_IRGRP | S_IROTH) == -1) {
        perror("chmod");
        exit(1);
    }
    printf("수정된 권한 출력하기: ");
    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("%o\n", statbuf.st_mode);

    printf("소유자 실행 권한 제거..\n");
    statbuf.st_mode &= ~(S_IXUSR);

    printf("그룹 사용자에게 쓰기 권한 추가..\n");
    statbuf.st_mode |= S_IWGRP;

    chmod("test.txt", statbuf.st_mode);
    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }

    printf("현재 권한 출력 : %o\n", statbuf.st_mode);
}