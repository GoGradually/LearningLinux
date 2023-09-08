#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int fd;
	char buf[10];
	fd = open(argv[1], O_RDONLY);
	int n;
	while((n=read(fd, buf, 5)) > 0){
		buf[n] = '\0';
		printf("%s", buf);
	}
	close(fd);
}

