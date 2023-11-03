#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    DIR *dirp = NULL;

    struct dirent *dt = NULL;

    if (!(dirp = opendir("."))) {
        perror("opendir");
        exit(1);
    }
    while (dt = readdir(dirp)) {
        printf("Inode: %d  ", (int)dt->d_ino);
        printf("%s\n", dt->d_name);
    }
    closedir(dirp);
}