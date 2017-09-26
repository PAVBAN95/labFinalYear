#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int sock, client, temp, clientSize, status;
	struct sockaddr_in serv_addr, cli_addr;
	char data[1025];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		printf("Unable to create Socket!");
		return 0;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(3001);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	temp = bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	if(temp < 0){
		printf("Unable to bind to given port!\n");
		return 0;
	}

	listen(sock, 5);
	clientSize = sizeof(cli_addr);
	client = accept(sock, (struct sockaddr *) &cli_addr, &clientSize);
	if(client < 0){
		printf("Problem in accepting!\n");
		return 0;
	}
	bzero(data, 1024);

	while(1){
		bzero(data, 1024);
		status = read(client, data, 1024);
		if(status < 0){
			printf("Error receiving data!\n");
			return 0;
		}
		printf("Message Received: %s", data);
		printf("Enter Message: ");
		bzero(data, 1024);
		fgets(data, 1024, stdin);
		status = write(client, data, strlen(data));
		if(status < 0){
			printf("Error Sending data!\n");
			return 0;
		}
	}
	return 0;
}