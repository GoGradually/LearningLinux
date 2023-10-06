#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (symlink("test.txt", "test.sym") == -1) {
        perror("symlink");
        exit(1);
    }
}