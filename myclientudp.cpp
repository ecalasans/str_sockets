//
// Created by Eric Calasans on 09/12/20.
//

#include "myclientudp.h"

myclientudp::myclientudp(uint16_t porta) {
    m_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (m_fd != 0){
        throw std::runtime_error(strerror(errno));
    }

    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(PORTA);
    m_addr.sin_addr.s_addr = inet_addr("192.168.0.7"); //Usar arpa/inet.h

    if (conecta() < 0){
        throw std::runtime_error(strerror(errno));
    }
}
