#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>

void f(){
	struct dirent *dent;
	DIR *dp;
	dp = opendir(".");

	while((dent = readdir(dp)) != NULL){
		printf("%s\n", dent->d_name);
	}
}

int main(){
	atexit(f);
}
