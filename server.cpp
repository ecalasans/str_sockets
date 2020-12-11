//
// Created by Eric Calasans on 11/12/20.
//
// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>

#define PORT	 4140
#define MAXLINE 1024

// Driver code
int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;
    int velocidades[4];

    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,
              sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len, n;

    len = sizeof(cliaddr); //len is value/resuslt

    recvfrom(sockfd, velocidades, sizeof(velocidades),
             MSG_WAITALL, (struct sockaddr *) &cliaddr, &len);
    if (len > 0){
        std::cout << cliaddr.sin_addr.s_addr << std::endl;
        for (int i = 0; i < 4; i++)
        {
            printf("Velocidade %d recebida:  %d\n", i, velocidades[i]);
        }
    } else {
        printf("Não veio nada!\n");
    }

    sendto(sockfd, (const char *)hello, strlen(hello),
           0, (const struct sockaddr *) &cliaddr,
           len);
    printf("Hello message sent.\n");

    return 0;
}




