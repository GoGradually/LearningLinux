#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buf[BUFSIZ];
    int n;

    n = readlink("test.sym", buf, BUFSIZ);

    if (n == -1) {
        perror("readlink");
        exit(1);
    }
    buf[n] = '\0';
    printf("test.sym : READLINK = %s\n", buf);
}