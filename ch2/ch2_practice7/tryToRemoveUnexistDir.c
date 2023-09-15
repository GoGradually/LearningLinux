#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	if(rmdir("han") == -1){
		perror("han");
		exit(1);
	}
}
