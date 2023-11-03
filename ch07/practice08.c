#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
int main(){
	pid_t pid;
	char buf[BUFSIZ];

	switch(pid = fork()){
		case -1:
			perror("fork()");
			exit(1);
		case 0:
			printf("child process\n");
			getcwd(buf, BUFSIZ);
			printf("pwd : %s\n", buf);
			exit(0);
		default:
			printf("parent process\n");
			DIR* dp;
			dp = opendir(".");
			struct dirent *dent;
			while((dent = readdir(dp)) !=NULL){
				printf("%s\n",dent->d_name);
			}
			closedir(dp);	
			break;
	}
}
