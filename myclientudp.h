//
// Created by Eric Calasans on 09/12/20.
//

#ifndef SOCKETS_MYCLIENTUDP_H
#define SOCKETS_MYCLIENTUDP_H

#define PORTA 4140
#define MAX_SIZE 0x10

#include <array>
#include <iostream>
#include <string>
#include <stdexcept>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class myclientudp {
    int m_fd;
    struct sockaddr_in m_addr;

public:
    //Construtor
    myclientudp(uint16_t porta);

    //Métodos
    int conecta();
    ssize_t envia(const std::string &buf);
    ssize_t recebe(std::array<char, MAX_SIZE> &buf);
    void echo();

    //Destrutor
    ~myclientudp();
};


#endif //SOCKETS_MYCLIENTUDP_H
