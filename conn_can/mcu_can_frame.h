//
// Created by Owner on 6/19/2025.
//

#ifndef MCU_CAN_FRAME_H
#define MCU_CAN_FRAME_H
#include <cstdint>

class mcu_can_frame {
    public:
    typedef struct {
        float v_in;
        float temp_mos1;
        float temp_mos2;
        float temp_mos3;
        float temp_mos4;
        float temp_mos5;
        float temp_mos6;
        float temp_pcb;
        uint16_t current_motor;
        uint16_t current_in;
        uint32_t rpm;
        uint16_t duty_now;
        float amp_hours;
        float amp_hours_charged;
        float watt_hours;
        float watt_hours_charged;
        int tachometer;
        int tachometer_abs;
    } mc_values;
    const mc_values telemetryframe;
    int wheel_diameter;
    float speed(float rpm){
        return (rpm * 3.14 * wheel_diameter *2.54 * 60)/1000;
    };  /* Calculates speed in km/h using wheel diameter (inches) */
    void telemetry(); /* Fills telemetry */
};
#endif //MCU_CAN_FRAME_H
