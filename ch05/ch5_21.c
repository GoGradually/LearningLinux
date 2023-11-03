#include <stdio.h>
#include <time.h>

char *output[] = {"%x %X", "%G년 %m월 %d일 %U주 %H:%M", "%r"};

int main() {
    struct tm *tm;
    time_t timep;
    int n;
    char buf[257];

    time(&timep);
    tm = localtime(&timep);

    for (n = 0; n < 3; n++) {
        strftime(buf, sizeof(buf), output[n], tm);
        printf("%s = %s\n", output[n], buf);
    }
}