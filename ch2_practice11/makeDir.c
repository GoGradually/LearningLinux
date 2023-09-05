#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	mkdir(argv[1], 0755);
	chdir(argv[1]);
	char* cwd = getcwd(NULL, BUFSIZ);
	printf("now dir : %s\n", cwd);
	free(cwd);
}
