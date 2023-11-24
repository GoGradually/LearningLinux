#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int comp(const void *a, const void *b){
	if(*(int*)a<*(int*)b) return -1;
	else if (*(int*)a==*(int*)b) return 0;
	else return 1;
}
int main(){
	int fd = open("number", O_RDWR);
	struct stat fileInfo;
	
	fstat(fd, &fileInfo);
	
	
	int *data = mmap(NULL, fileInfo.st_size, PROT_READ | PROT_WRITE,MAP_SHARED,fd, 0);
	if(data==MAP_FAILED){
		perror("Error mmapping the file");
		exit(1);
	}
	size_t num = fileInfo.st_size / sizeof(int);
    qsort(data, num, sizeof(int), comp);

	if(msync(data, fileInfo.st_size, MS_SYNC)==-1){
		perror("Could not sync the file to dist");
	}
	if(munmap(data, fileInfo.st_size)==-1){
		perror("Error un-mmapping the file");
	}

	close(fd);
	return 0;
}
