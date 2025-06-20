//
// Created by Owner on 6/19/2025.
//

#ifndef CAN_H
#define CAN_H
#include <cstdint>
#include <queue>
#include <linux/can.h>


class can {
    public:
    struct can_frame frame;     /* CAN FRAME */
    int can_open_socket(char ifname );  /* Opens Can Socket and returns an integer FD (File Descriptor) */
    int can_close_socket(int canfd); /* Closes CAN socket and returns 1 */
    int can_send(struct can_frame *frame);     /*Sends a filled CAN frame, returns nbyte when successfully executed */
    bool can_receive(can_frame& out_frame);  /* Fills a CAN buffer, returns true when successfully executed */
    uint32_t float2int(float val);  /* Converts Float to Unsigned 32-bit integer */

    int getsockfd() {
        return sockfd;
    }

    int canfd;  /* CAN File Descriptor */
    uint8_t controller_id; /* VESC Controller_ID */

    void queueFrame(struct can_frame &frame);
    void sendFrame(struct can_frame frame);
    bool haspendingframes() const;

private:
    int sockfd; /*Secret Sock use getsockfd() to access */
    std::queue<struct can_frame> txBuffer;  /*TX Queue, prevents memory violations */

};



#endif //CAN_H
