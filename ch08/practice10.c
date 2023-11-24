#include <signal.h>
#include <stdio.h>

int main(){
	sigset_t s;
	sigfillset(&s);

	if(sigismember(&s,SIGBUS)){
		printf("SIGBUS is existed\n");
		sigdelset(&s, SIGBUS);
	}
	if(!sigismember(&s, SIGBUS)){
		printf("SIGBUS is deleted\n");
	}
	return 0;
}
