#include <stdio.h>
#include <time.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char buf[256];
	struct sockaddr_un ser, cli;

	int sd, nsd;
	int len, nlen;

	memset((char* )&ser, '\0', sizeof(ser));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path, "joonho_socket");
	
	if((sd=socket(AF_UNIX, SOCK_STREAM, 0))==-1){
		perror("socket");
		exit(1);
	}
	len = sizeof(ser.sun_family) + strlen(ser.sun_path);

	if(bind(sd, (struct sockaddr*) &ser, len)){
		perror("bind");
	}
	int pwnum[5] = {1234, 2345, 3456, 4567, 5678};
	if(listen(sd, 5)<0){
		perror("listen");
		exit(1);
	}

	while(1){
		printf("Waiting...\n");
		if((nsd = accept(sd, (struct sockaddr*) &cli, &nlen))==-1){
			perror("accept");
			exit(1);
		}
		srand((unsigned int)time(NULL));
		int randnum = rand()%5;
		sprintf(buf, "plz write a security code %d :", randnum + 1);
		if(send(nsd, buf, sizeof(buf), 0)==-1){
			perror("send");
			exit(1);
		}
		if(recv(nsd, buf,sizeof(buf), 0) == -1){
			perror("recv");
			exit(1);
		}
		int input = atoi(buf);
		if(input == pwnum[randnum]){
			sprintf(buf, "Valid Security Number\n");
		}else{
			sprintf(buf, "Not Valid Security Number!!!\n");
		}
		if(send(nsd, buf, sizeof(buf), 0)==-1){
			perror("send");
			exit(1);
		}
		close(nsd);
	}
	close(sd);
	return 0;
}	
