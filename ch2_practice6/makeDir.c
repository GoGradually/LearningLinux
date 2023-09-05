#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	if(mkdir("dir1", 0755) == -1){
		perror("dir1");
		exit(1);
	}
	if(mkdir("dir2", 0755) == -1){
		perror("dir2");
		exit(1);
	}
	if(rmdir("dir1") == -1){
		perror("dir1");
		exit(1);
	}
	if(rename("dir2", "hanbit")==-1){
		perror("dir2");
		exit(1);
	}
}
