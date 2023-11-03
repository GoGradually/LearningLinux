#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	char* argv[3] = {"vi", "/etc/hosts", NULL};
	if(execvp("vi",argv) == -1){
		perror("execvp");
		exit(1);
	}
}
