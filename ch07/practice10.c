#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	pid_t pid;

	switch(pid = fork()){
		case -1:
			perror("fork()");
			exit(1);
		case 0:
			printf("I'm child process\n");
			pid_t childPID;
			childPID = fork();
			printf("my cChild process : %d\n", (int)childPID);
			break;
		default:
			printf("I'm parent process\n");
			printf("my child process = %d\n", (int)pid);
			break;
	}
}

