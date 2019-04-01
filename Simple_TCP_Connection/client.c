#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12000

int main(){

	int clientSocket, meh;
	struct sockaddr_in servAddr;

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("Unable to create Socket.\n");
		exit(1);
	} else 
	{
	printf("Client Socket is created.\n");
	}
         servAddr.sin_family = AF_INET;
         servAddr.sin_addr.s_addr = INADDR_ANY;
         servAddr.sin_port =  htons (12000);
		 
	meh = connect(clientSocket, (struct sockaddr*)&servAddr, sizeof(servAddr));
	if(meh < 0)
	{
		printf("Failed to connect.\n");
		exit(1);
		}
	printf("Connection established.\n");
	return 0;
	}
