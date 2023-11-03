#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int n;
	extern char *optarg;
	extern int optind;
	
	if(argc == 1){
		printf("-p : welcome linux system programming!\n");
		printf("-n : nice to meet you\n");
		printf("-h : help\n");
		return 0;
	}
	while((n = getopt(argc, argv, "pn:h")) != -1){
		switch(n){
			case 'p':
				printf("Welcome Linux System Programming!\n");
				break;
			case 'n':
				printf("Nice to meet %s\n", optarg);
				break;
			case 'h':
		                printf("-p : welcome linux system programming!\n");
			       	printf("-n : nice to meet you\n");
				printf("-h : help\n");
				break;
		}
	}
}
