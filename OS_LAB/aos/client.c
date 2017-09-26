#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int sock, status;
	struct sockaddr_in serv_addr, cli_addr;
	char data[1025];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		printf("Error creating socket\n");
		return 0;
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(3001);

	status = inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
	if(status <= 0){
		printf("Error converting!\n");
		return 0;
	}

	status = connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	if(status < 0){
		printf("Error connecting\n");
	}

	while(1){
		printf("Enter your message: ");
		memset(&data, 0, sizeof(data));
		fgets(data, 1024, stdin);
		status = write(sock, data, strlen(data));
		if(status < 0){
			printf("Error writing message!");
			return 0;
		}

		memset(&data, 0, sizeof(data));
		status = read(sock, data, 1024);
		printf("Message: %s\n", data);
	}
	
	return 0;
}