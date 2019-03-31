#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>

#define PORT 12000

int main(){

        int sockfd, meh;
         struct sockaddr_in servAddr;

        int newSocket;
        struct sockaddr_in cliAddr;

        socklen_t cliSize;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0){
                printf("Unable to create Socket.\n");
                exit(1);
        } else
        {
        printf("Server Socket is created.\n");
		}

         servAddr.sin_family = AF_INET;
         servAddr.sin_addr.s_addr = INADDR_ANY;
         servAddr.sin_port =  htons (12000);

        meh = bind(sockfd, (struct sockaddr*) & servAddr, sizeof(servAddr)) < 0;
        if (meh < 0) {
                printf("ERROR in binding.\n");
                exit(1);
        } else
        {
        printf("Bind to port %d\n", 12000);
        }
        if(listen(sockfd, 10) == 0){
                printf("Listening....\n");
        }else{
                printf("Error in connection.\n");
        }

        while (1) {
                newSocket = accept(sockfd, (struct sockaddr*)&cliAddr, &cliSize);
                if(newSocket < 0){
						exit(1);
				}
                printf("Connection accepted from %s:%d\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));
        }
		close(newSocket);
		close(sockfd);
        return 0;
    }