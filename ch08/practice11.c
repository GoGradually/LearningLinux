#include <stdio.h>
#include <signal.h>

void handler(int sig){
	printf("signal %d handled", sig);
}

int main(){
	struct sigaction act;
	act.sa_flags = SA_RESETHAND;
	act.sa_handler = handler;

	sigaction(SIGQUIT, &act, NULL);

	raise(SIGQUIT);
	printf("alive\n");
	raise(SIGQUIT);
	printf("still alive\n");
	return 0;
}
