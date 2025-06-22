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
    mc_values telemetryframe;
    mcu_can_frame() : telemetryframe{} {};

    static mcu_can_frame telemetryfunc;

    int wheel_diameter;
    float speed(float rpm){
        float wheel_circ = wheel_diameter * 0.0254f *3.14159f;
        float speed_m_per_min = rpm * wheel_circ;
        float speed_kmh = (speed_m_per_min * 60) / 1000;
        return speed_kmh;
    };  /* Calculates speed in km/h using wheel diameter (inches) */
    void telemetry(can_frame frame); /* Fills telemetry */
};

#endif //MCU_CAN_FRAME_H
