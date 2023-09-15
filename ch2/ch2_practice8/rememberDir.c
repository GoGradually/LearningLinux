#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
	char *cwd, *rwd;

	if((rwd = getcwd(NULL, BUFSIZ)) == NULL){
		perror("CAN'T REMEMBER NOW DIR");
		exit(1);
	}
	printf("rememberd dir : %s\n", rwd);

	if(mkdir("bit", 0755) == -1){
		perror("bit");
		exit(1);
	}
	if(chdir("bit") == -1){
		perror("can't move to bit");
		exit(1);
	}
	if((cwd = getcwd(NULL, BUFSIZ)) == NULL){
		perror("CAN'T READ NOW DIR");
		exit(1);
	}
	printf("now dir : %s\n", cwd);
	free(cwd);

	if(chdir(rwd) == -1){
		perror("can't move to rwd");
		exit(1);
	}
	if((cwd = getcwd(NULL, BUFSIZ)) == NULL){
		perror("CAN'T READ NOW DIR");
		exit(1);
	}
	printf("comeback dir : %s\n", cwd);
	free(cwd);
	free(rwd);
}

