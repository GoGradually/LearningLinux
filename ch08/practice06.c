#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(){
	raise(SIGUSR1);
	printf("printing statement\n");
	return 0;
}
