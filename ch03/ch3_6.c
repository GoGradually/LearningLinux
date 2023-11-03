#include <stdio.h>
#include <unistd.h>

int main(){
    if(access("test.txt.bak", F_OK)==-1){
        printf("test.txt.bak 존재하지 않는다.\n");
    }
    if(access("test.txt", R_OK)==-1){
        printf("실사용자 읽기권한이 없다.\n");
    }
    if(access("test.txt", X_OK)==-1){
        printf("실사용자 실행권한이 없다.\n");
    }
}