#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(){
	DIR *dp;
	struct dirent *dent;

	dp = opendir("temp");
	int cnt = 0;
	while(dent = readdir(dp)){
		printf("Name : %s ", dent->d_name);
		printf("Inode : %d \n", (int)dent->d_ino);
		cnt++;
	}
	if(cnt == 2){
		rmdir("temp");
	}
	closedir(dp);
}
