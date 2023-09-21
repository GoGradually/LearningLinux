#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    if (mkdir("han", 0755) == -1) {
        perror("han");
        exit(1);
    }
}