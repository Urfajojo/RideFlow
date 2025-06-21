//
// Created by Owner on 6/19/2025.
//

#include "can.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

can can::currentcan;

int can::can_open_socket(const char* ifname) {
    struct sockaddr_can addr;
    struct ifreq ifr;
    const char **ifn = &ifname;
    int loopback = 1;
    canfd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    setsockopt(canfd, SOL_CAN_RAW, CAN_RAW_LOOPBACK, &loopback, sizeof(loopback));

    if (canfd == -1) {
        perror ("Error while opening socket");
        return -1;
    };

    addr.can_family  = AF_CAN;
    std::strcpy(ifr.ifr_ifrn.ifrn_name, ifname);
    if (ioctl(canfd, SIOCGIFINDEX, &ifr) < 0) {
        perror("CAN Ioctl error");
        return -1;
    }
    addr.can_ifindex = ifr.ifr_ifindex;

    printf("%s at index %d\n", ifn, ifr.ifr_ifindex);

    if (bind(canfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error in socket bind");
        return -2;
    }
    return canfd;
}

int can::can_close_socket(int canfd) {
    close(canfd);
    return 1;
}

u_int32_t can::float2int(float val) {
    uint32_t value = val * 10000;
    return value;
}

int can::can_send(struct can_frame *frame) {
    if (write(canfd, &frame, sizeof(frame)) == -1) {
        perror("Error in sending");
        return -1;
    } else {
        return sizeof(frame);
    }
}

void can::queueFrame(struct can_frame& frame) {
    txBuffer.push(frame);
}

void can::sendFrame(struct can_frame frame) {
    if (!txBuffer.empty()) {
        can_frame tx = txBuffer.front();
        ssize_t bytes = can_send(&tx);
        if (bytes == sizeof(tx)) {
            txBuffer.pop();
        } else {
            perror("Error in sending");
        }
    }
}

bool can::haspendingframes() const {
    return !txBuffer.empty();
}

can_frame can::received_frame;

int can::can_receive() {
    ssize_t bytes = read(canfd, &received_frame, sizeof(received_frame));
    if (bytes == -1) {
        perror("Error in receiving");
        return -1;
    } else if (bytes < sizeof(received_frame)) {
        perror("Incomplete frame received");
        return -1;
    } else
        return bytes;
}

void can::cansendtest(int sock) {
    std::cout << "CAN Daemon send test" << std::endl;
    can_frame testframe;
    testframe.can_id = 0x12;
    testframe.can_dlc = 2;
    testframe.data[0] = 0xAB;
    testframe.data[1] = 0xCD;
        while (true) {
            ssize_t n = write(sock, &testframe, sizeof(testframe));
            if (n == -1) {
                perror("write fail");
            } else;
            {
                std::cout << "Test frame sent" << std::endl;
                sleep(0.5);
            }

        }

}


void can::canreadtest(int sock) {
    std::cout << "CAN Daemon read test" << std::endl;
    while (true) {
        if (can_receive() > 0) {
            std::cout << "Frame detected from" << received_frame.can_id << std::endl;
            sleep(0.5);
        }
    }
}



