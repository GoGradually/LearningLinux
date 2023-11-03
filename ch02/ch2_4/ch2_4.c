#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *curPath = NULL;

    if ((curPath = get_current_dir_name()) == NULL) {
        perror("get_current_dir_name");
        exit(1);
    }
    printf("curPath = %s\n", curPath);
    free(curPath);
}