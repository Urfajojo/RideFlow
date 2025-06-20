//
// Created by Owner on 6/19/2025.
//
#include "mcu_can_frame.h"

#include <unistd.h>

#include "can.h"

void mcu_can_frame::telemetry() {
    mc_values telemetryframe;
    can_frame received_frame;
    can can1;
    while(true){
        can1.can::can_receive(received_frame);
        if (received_frame.can_id ==  0x00000900) {
            telemetryframe.rpm = received_frame.data[0, 4];
            telemetryframe.current_in = received_frame.data[4, 2];
            telemetryframe.duty_now = received_frame.data[6, 2];
            sleep(0.5);
        }
    }

}