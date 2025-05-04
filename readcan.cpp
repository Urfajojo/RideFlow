//
// Created by Owner on 4/30/2025.
//

#include "readcan.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include "opensocket.h"
#include <linux/can.h>
#include "ctgmath"

int sendcan(can_frame) {
    if (isopen == false) {
        std::cout << "CAN Bus inactive";
        throw std::runtime_error("CAN Bus Inactive");
    }else;
    int bytes = send(sock, &frame , sizeof(can_frame), 0);
    if (bytes != sizeof(can_frame)) {
        std::cout << "CAN Bus Error";
        throw std::runtime_error("CAN Bus Error");
    }
return bytes;
}

int readcan(can_frame) {
    if (isopen == false) {
        std::cout << "CAN Bus Inactive";
        throw std::runtime_error("CAN Bus Inactive"); //Error throw
    }
    int bytes = read(sock, &frame, sizeof(can_frame)); //Fills the RX frame with read data
    if (bytes != sizeof(can_frame)) {
        std::cout << "Empty Message";
        throw std::runtime_error("Empty Message"); //Empty message error
    }
return bytes; // Sends the data with an 8 bit unsigned integer
}
