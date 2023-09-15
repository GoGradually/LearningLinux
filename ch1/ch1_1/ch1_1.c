#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(){
	if(access("test.txt", F_OK) == -1){
		printf("errno = %d\n", errno);
	}
	return 0;
}
