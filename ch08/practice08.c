#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void handler(int sig){
	printf("signal handled\n");
}

int main(){
	if(signal(SIGILL, handler)==SIG_ERR){
		perror("signal");
		exit(1);
	}
	raise(SIGILL);
	printf("Sigill handled\n");

	if(signal(SIGILL, SIG_DFL)==SIG_ERR){
		perror("signal default");
		exit(1);
	}
	raise(SIGILL);
	return 0;
}
