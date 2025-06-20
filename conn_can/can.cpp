//
// Created by Owner on 6/19/2025.
//

#include "can.h"

#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int can::can_open_socket(char ifname) {
    struct sockaddr_can addr;
    struct ifreq ifr;
    const char *ifn = &ifname;
    canfd == socket(PF_CAN, SOCK_RAW, CAN_BCM);

    if (canfd == -1) {
        perror ("Error while opening socket");
        return -1;
    };

    addr.can_family  = AF_CAN;
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
        return frame->can_id;
    }
}

void can::queueFrame(struct can_frame& frame) {
    txBuffer.push(frame);
}

void can::sendFrame(struct can_frame frame) {
    if (!txBuffer.empty()) {
        can_frame tx = txBuffer.front();
        ssize_t bytes = can::can_send(&tx);
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

bool can::can_receive(can_frame& out_frame) {
    ssize_t bytes = read(canfd, &out_frame, sizeof(out_frame));
    if (bytes == -1) {
        perror("Error in receiving");
        return false;
    } else if (bytes < sizeof(out_frame)) {
        perror("Incomplete frame received");
        return false;
    } else
        return true;
}





