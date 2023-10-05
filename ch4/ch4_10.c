#include <stdio.h>
#include <stdlib.h>

int main() {
    int ret;

    ret = remove("tmp.bbb");
    if (ret == -1) {
        perror("Remove tmp.bbb");
        exit(1);
    }
    printf("Remove tmp.bbb success!!!\n");
}