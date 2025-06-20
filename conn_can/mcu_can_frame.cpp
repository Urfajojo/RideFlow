//
// Created by Owner on 6/19/2025.
//
#include "mcu_can_frame.h"

#include <iostream>
#include <unistd.h>

#include "can.h"

mcu_can_frame::mc_values telemetryframe;

void mcu_can_frame::telemetry() {
    can_frame received_frame;
    while(true){
        can::currentcan.can::can_receive(received_frame);
        if (received_frame.can_id ==  0x00000900) {
            telemetryframe.rpm = received_frame.data[0, 4];
            telemetryframe.current_in = received_frame.data[4, 2];
            telemetryframe.duty_now = received_frame.data[6, 2];
            sleep(0.5);
        }
        else {
            std:
                std::cout << received_frame.data;
        }
    }

}