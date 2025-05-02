//
// Created by Owner on 4/30/2025.
//

#include "readcan.h"

#include <iostream>
#include <libsocketcan.h>
#include <unistd.h>
#include <sys/socket.h>
#include "opensocket.h"
#include <net/if.h>

#include "ctgmath"
 struct CANTxFrame{
    struct {
        uint8_t DLC:4; /**< @brief Data length. */
        uint8_t RTR:1; /**< @brief Frame type. */
        uint8_t IDE:1; /**< @brief Identifier type. */
    };
    union {
        struct {
            uint32_t SID:11; /**< @brief Standard identifier.*/
        };
        struct {
            uint32_t EID:29; /**< @brief Extended identifier.*/
        };
    };
    union {
        uint8_t data8[8]; /**< @brief Frame data. */
        uint16_t data16[4]; /**< @brief Frame data. */
        uint32_t data32[2]; /**< @brief Frame data. */
    };
};
struct CANRxFrame{
    struct {
        uint8_t DLC:4; /**< @brief Data length. */
        uint8_t RTR:1; /**< @brief Frame type. */
        uint8_t IDE:1; /**< @brief Identifier type. */
    };
    union {
        struct {
            uint32_t SID:11; /**< @brief Standard identifier.*/
        };
        struct {
            uint32_t EID:29; /**< @brief Extended identifier.*/
        };
    };
    union {
        uint8_t data8[8]; /**< @brief Frame data. */
        uint16_t data16[4]; /**< @brief Frame data. */
        uint32_t data32[2]; /**< @brief Frame data. */
    };
};
int sendcan(CANTxFrame *txFrame) {
    if (isopen == false) {
        std::cout << "CAN Bus inactive";
        throw std::runtime_error("CAN Bus Inactive");
    }else;
    return 1;
}

uint8_t readcan(CANRxFrame *rxFrame) {
    if (isopen == false) {
        std::cout << "CAN Bus Inactive";
        throw std::runtime_error("CAN Bus Inactive"); //Error throw
    }
    uint8_t bytes = read(sock, rxFrame, sizeof(rxFrame->data8)); //Fills the RX frame with read data
    if (bytes != sizeof(rxFrame->data8)) {
        std::cout << "Empty Message";
        throw std::runtime_error("Empty Message"); //Empty message error
    }

return bytes; // Sends the data with an 8 bit unsigned integer
}
