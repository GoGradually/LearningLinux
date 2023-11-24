#include <signal.h>
#include <stdio.h>

int main(){
	sigset_t s;
	sigaddset(&s, SIGQUIT);
	sigaddset(&s, SIGILL);
	sigaddset(&s, SIGTRAP);
	if(sigismember(&s, SIGQUIT)){
		printf("SIGQUIT existed.\n");
	}
	if(sigismember(&s, SIGILL)){
		printf("SIGILL existed.\n");
	}
	if(sigismember(&s, SIGTRAP)){
		printf("SIGTRAP existed.\n");
	}
	return 0;
}
