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
    int sockfd;
    struct sockaddr_in serverAddr;

    int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;
    char buffer[1024];

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    printf("[+] Server socket created successfully\n");
    memset(&serverAddr, '\0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("[+] Bind to the port 12345\n");

    listen(sockfd, 5);
    printf("[+] Listening\n");

    addr_size = sizeof(newAddr);

    while(1){
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        recv(newSocket, buffer, 1024, 0);
        printf("Data Receieved: %s\n", buffer);
    }

    return;
}