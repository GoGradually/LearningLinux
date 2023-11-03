#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    struct stat statbuf;

    if (stat("test.txt", &statbuf) == -1) {
        perror("stat");
        exit(1);
    }
    printf("소유자 : \n");
    if ((statbuf.st_mode & S_IRUSR) != 0)
        printf("소유자 권한 체크 : 읽기 권한 있음\n");
    if ((statbuf.st_mode & S_IWUSR) != 0)
        printf("소유자 권한 체크 : 쓰기 권한 있음\n");
    if ((statbuf.st_mode & S_IXUSR) != 0)
        printf("소유자 권한 체크 : 실행 권한 있음\n");

    printf("그룹 : \n");
    if ((statbuf.st_mode & S_IRGRP) != 0)
        printf("그룹 권한 체크 : 읽기 권한 있음\n");

    if ((statbuf.st_mode & (S_IREAD >> 3)) != 0)
        printf("그룹권한 : 읽기권한 있음\n");
}