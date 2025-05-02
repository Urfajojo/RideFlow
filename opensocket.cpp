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



int openSocket(const char*interfacename) {
    int sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    int socklen = sizeof(struct can_frame);
    int sockaddr_len = sizeof(struct sockaddr_can);
    bool isopen;
    if (sock < 0) {
        isopen = false;
        throw std::runtime_error("Failed to open socket if you read this the program executes");

    }
    unsigned int ifindex = if_nametoindex(interfacename);
    if (ifindex == 0) {
        close(sock);
        isopen = false;
        throw std::runtime_error("Failed to find interface");
    }
    struct sockaddr_can addr{};
    addr.can_family = AF_CAN;
    addr.can_ifindex = static_cast<int>(ifindex);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sock);
        isopen = false;
        throw std::runtime_error("Failed to bind");
    }
    isopen = true;
    std::cout << interfacename << " opened socket and succesfully bound to " << ifindex << std::endl;
return sock;
}