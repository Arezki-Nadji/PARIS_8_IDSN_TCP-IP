#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455

void main(){
	int sockfd;
	struct sockaddr_in serverAddr;
	
	int newSocket;
	struct sockaddr_in newAddr;
	
	socklen_t addr_size;
	char buffer[1024];
	
	sockfd=socket(PF_INET,SOCK_STREAM,0);
	printf("{+}Server Socket Created Sucessfully\n");
	memset(&serverAddr,'\0',sizeof(serverAddr));
	
	serverAddr.sin_family=AF_INET,
	serverAddr.sin_port=htons(PORT);
	serverAddr.sin_addr.s_addr=inet_addr("192.168.1.71");
	
	bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	printf("{+}Bind to the Port Number %d\n",4455);
	
	listen(sockfd,5);
	addr_size=sizeof(newAddr);
	
	printf("{+}Listening...\n");
	
	newSocket=accept(sockfd,(struct sockaddr*)&newAddr,&addr_size);
	
	strcpy(buffer,"Hello Am the Raspi\n");
	send(newSocket,buffer,strlen(buffer),0);
	printf("{+}Send the data to the Client\n");
	printf("{+}Closing the Connection\n");
}

