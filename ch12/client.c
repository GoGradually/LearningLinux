#include <stdio.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int sd, len;
	char buf[256];
	struct sockaddr_un ser;

	if((sd = socket(AF_UNIX, SOCK_STREAM, 0))==-1){
		perror("socket");
		exit(1);
	}

	memset((char*)&ser, '\0', sizeof(ser));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path, "joonho_socket");
	len = sizeof(ser.sun_family) + strlen(ser.sun_path);

	if(connect(sd, (struct sockaddr*) &ser, len)<0){
		perror("connect");
		exit(1);
	}
	if(recv(sd, buf, sizeof(buf)+1, 0)==-1){
		perror("recv");
		exit(1);
	}
	printf("%s", buf);
	memset(buf, '\0', sizeof(buf));
	fgets(buf,sizeof(buf), stdin);
	if(send(sd, buf, sizeof(buf)+1, 0)==-1){
		perror("send");
		exit(1);
	}
	if(recv(sd, buf, sizeof(buf)+1, 0) == -1){
		perror("recv");
		exit(1);
	}
	printf("%s", buf);
	close(sd);
	return 0;
}
