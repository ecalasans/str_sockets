#include <iostream>
#include "myclientudp.h"

int main() {
    system("clear");
    printf("***\tPROGRAMA CLIENTE\t***\n");

    try {
        myclientudp cliente_udp(PORTA);
        cliente_udp.echo();

    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
