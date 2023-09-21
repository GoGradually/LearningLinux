#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    DIR *dirp = NULL;

    struct dirent *dt = NULL;

    long loc;

    if (!(dirp = opendir("."))) {
        perror("opendir");
        exit(1);
    }
    printf("현재 항목의 위치 : %ld\n", telldir(dirp));
    printf("항목 별 읽기 시작 ...\n");
    while (dent = readdir(dirp)) {
        printf("위치: %ld  -> %s\n", telldir(dirp), dent->d_name);
    }
    printf("\n디렉터리의 첫 번째 위치 돌리기 시작 ...\n");
    rewinddir(dirp);
    printf("현재 위치: %ld\n", telldir(dirp));

    // readdir 이용한 위치 이동
    dent = rewinddir(dirp);
    loc = telldir(dirp);
    printf("두 번째 위치: %ld\n", loc);
    printf("두 번째 파일 이름: %s\n", dent->d_name);

    closedir(dirp);
}