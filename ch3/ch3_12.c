#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[BUFSIZ];

    char *str = NULL;

    printf("동적할당 방식 ");
    str = realpath("test.sym", NULL);
    if (!str) {
        perror("realpath");
        exit(1);
    }
    printf("test.txt -> realpath = %s\n", str);
    free(str);

    printf("static 방식 ");
    if (!realpath("test.sym", buf)) {
        perror("realpath");
        exit(1);
    }
    printf("test.txt -> realpath = %s\n", buf);
}