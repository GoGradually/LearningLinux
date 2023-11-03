#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    if (rename("han", "bit") == -1) {
        perror("rename");
        exit(1);
    }
}