#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	pid_t pid;
	int status;
	switch(pid = fork()){
		case -1:
			perror("fork()");
			exit(1);
		case 0:
			printf("I'm child process: %d\n",(int)getpid());
			pid_t childPID = fork();
			printf("my parent process : %d\n", (int)getppid());
			exit(0);
		default:
			printf("I'm parent process: %d\n", (int)getpid());
			printf("my child process = %d\n", (int)pid);
			while(wait(&status) != pid) continue;
			exit(0);
	}
}

