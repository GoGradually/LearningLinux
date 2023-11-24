#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	switch(pid = fork()){
		case -1:
			perror("fork()");
			exit(1);
		case 0:
			if(execl("/var/run/utmp","who", (char*) NULL)==-1){
				perror("execl()");
				exit(1);
			}
			exit(0);
		default: 
			printf("Parent Process.\n");
			exit(0);
	}
}
