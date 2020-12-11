//
// Created by Eric Calasans on 11/12/20.
//

#define PORTA 4140
#define MAX_SIZE 0x10

#include <array>
#include <iostream>
#include <stdexcept>

#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "myserverudp.h"

int main(){
    system("clear");
    try{
        myserverudp servidor(PORTA);
        servidor.echo();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return 0;
}

