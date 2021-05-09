#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 12345

void main()
{
	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	printf("[+] Client Socket created successfully\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	while(1)
	{
		printf("Press 1 to exit else to send message: ");
		scanf("%d",&x);
		if(x==1)
		break;
		else
		{
			clientSocket = socket(PF_INET, SOCK_STREAM, 0);
			printf("[+] Client Socket created successfully\n");
			connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
			printf("[+] Connected to the server\n");	
			scanf("%c",&temp);
			printf("Enter the message to be sent: ");
			scanf("%[^\n]c", message);
			strcpy(buffer, message);
			send(clientSocket, buffer, strlen(buffer), 0);
		}
	}

	return;
}
