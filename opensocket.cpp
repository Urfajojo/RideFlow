//
// This is where magic happens, jk it reads speed and shit from the can
//

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <libsocketcan.h>

int sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
int openSocket(const char*interfacename) {
    if (sock < 0) {
        throw std::runtime_error("Failed to open socket if you read this the program executes");
    }
    unsigned int ifindex = if_nametoindex(interfacename);
    if (ifindex == 0) {
        close(sock);
        throw std::runtime_error("Failed to find interface");
    }
    struct sockaddr_can addr{};
    addr.can_family = AF_CAN;
    addr.can_ifindex = static_cast<int>(ifindex);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sock);
        throw std::runtime_error("Failed to bind");
        return 1;
    }
    std::cout << interfacename << " opened socket and succesfully bound to " << ifindex << std::endl;
return sock;
}