//
// Created by Owner on 6/19/2025.
//
#include "mcu_can_frame.h"

#include <iostream>
#include <unistd.h>

#include "can.h"

mcu_can_frame::mc_values telemetryframe;

void mcu_can_frame::telemetry(can_frame frame) {
    uint16_t current;
    uint32_t rpm;
    uint16_t duty;
    float speed;
    uint32_t amphours;
    uint32_t amphourscharged;
    uint32_t watthours;
    uint32_t watthourscharged;
    uint16_t temp1;
    uint16_t temp2;
    switch (frame.can_id) {
        case 0x0900:
            memcpy(&rpm, &frame.data[0], 4);
            memcpy(&current, &frame.data[4], 2);
            memcpy(&duty, &frame.data[6], 2);
            current = current / 10;
            duty = duty / 1000;
            rpm = __bswap_32(rpm);
            speed = mcu_can_frame::speed(rpm);

            telemetryframe.duty_now = __bswap_16(duty);
            telemetryframe.current_in = __bswap_16(current);
            telemetryframe.speed = speed;
            telemetryframe.rpm = rpm;

            std::cout << "CAN_PACKET_STATUS_1" << std::endl;
            break;
        case 0x0E00:
            memcpy(&amphours, &frame.data[0], 4);
            memcpy(&amphourscharged, &frame.data[4], 4);

            amphours = __bswap_32(amphours);
            amphourscharged = __bswap_32(amphourscharged);

            telemetryframe.amp_hours = amphours / 10000;
            telemetryframe.amp_hours_charged = amphourscharged / 10000;
            std::cout << "CAN_PACKET_STATUS_2" << std::endl;
            break;
        case 0x0F00:
            memcpy(&watthours, &frame.data[0], 4);
            memcpy(&watthourscharged, &frame.data[4], 4);

            watthours = __bswap_32(watthours);
            watthourscharged = __bswap_32(watthourscharged);

            telemetryframe.watt_hours = watthours / 10000;
            telemetryframe.watt_hours_charged = watthourscharged / 10000;
            std::cout << "CAN_PACKET_STATUS_3" << std::endl;
            break;
        case 0x1000:
            memcpy(&temp1, &frame.data[0], 2);
            memcpy(&temp2, &frame.data[2], 2);

            temp1 = __bswap_16(temp1);
            temp2 = __bswap_16(temp2);

            telemetryframe.temp_pcb = temp1 * 10;
            telemetryframe.temp_mos1 = temp2 * 10;
            std::cout << "CAN_PACKET_STATUS_4" << std::endl;
            break;
        default:
            std::cout << "CAN_PACKET_INVALID" << std::endl;
            break;
    }
}