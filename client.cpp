//
// Created by Eric Calasans on 11/12/20.
//
// Client side implementation of UDP client-server model
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
    char *hello = "Hello from client";
    int velocidades[4];

    struct sockaddr_in	 servaddr;

    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Socket criado com sucesso!!\n");
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("192.168.0.7");

    socklen_t n, len;

    //Preenche as velocidades
    for (int i = 0; i < 4; ++i) {
        printf("Velocidade %d:  ", i);
        std::cin >> velocidades[i];
    }

    sendto(sockfd, velocidades, sizeof(velocidades),
           0, (const struct sockaddr *) &servaddr, sizeof(servaddr));

//    sendto(sockfd, (const char *)hello, strlen(hello),
//           0, (const struct sockaddr *) &servaddr,
//           sizeof(servaddr));
    //printf("Hello message sent.\n");

    n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                 MSG_WAITALL, (struct sockaddr *) &servaddr,
                 &len);
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);

    close(sockfd);
    return 0;
}

