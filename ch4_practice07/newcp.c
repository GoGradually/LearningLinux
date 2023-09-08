#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int fd1, fd2;
	int n;
	char buf[10];
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT|O_RDWR,0744);
	while((n=read(fd1, buf, 5)) > 0){
		buf[n] = '\0';
		int m;
		if((m = write(fd2, buf, n)) != n) perror("write");
	}
	close(fd1);
	close(fd2);
}
