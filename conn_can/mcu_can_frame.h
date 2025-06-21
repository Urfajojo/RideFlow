//
// Created by Owner on 6/19/2025.
//

#ifndef MCU_CAN_FRAME_H
#define MCU_CAN_FRAME_H
#include <cstdint>
#include <QObject>
#include <linux/can.h>

class mcu_can_frame {
    public:
    typedef struct {
        mutable float v_in;
        mutable float temp_mos1;
        float temp_mos2;
        float temp_mos3;
        float temp_mos4;
        float temp_mos5;
        float temp_mos6;
        mutable float temp_pcb;
        mutable float current_motor;
        mutable float current_in;
        mutable float rpm;
        mutable float duty_now;
        mutable float amp_hours;
        mutable float amp_hours_charged;
        mutable float watt_hours;
        mutable float watt_hours_charged;
        mutable float speed;
        int tachometer;
        int tachometer_abs;
    } mc_values;
    const mc_values telemetryframe;
    int wheel_diameter;
    float speed(float rpm){
        return (rpm * 3.14 * wheel_diameter *2.54 * 60)/1000;
    };  /* Calculates speed in km/h using wheel diameter (inches) */
    void telemetry(can_frame frame); /* Fills telemetry */
};
#endif //MCU_CAN_FRAME_H
