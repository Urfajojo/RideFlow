//
// Created by vboxuser on 6/22/25.
//
#pragma once
#ifndef TELEMETRYMODEL_H
#define TELEMETRYMODEL_H

#include <QObject>
#include <linux/can.h>
#include "mcu_can_frame.h"

class TelemetryModel : public  QObject {
    Q_OBJECT
    Q_PROPERTY(float rpm READ rpm NOTIFY rpmChanged)
    Q_PROPERTY(float speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(float voltage READ voltage NOTIFY voltageChanged)
    Q_PROPERTY(float amp_hours READ amp_hours NOTIFY amp_hoursChanged)
    Q_PROPERTY(float amp_hours_charged READ amp_hours_charged NOTIFY amp_hours_chargedChanged)
    Q_PROPERTY(float watt_hours READ watt_hours NOTIFY watt_hoursChanged)
    Q_PROPERTY(float watt_hours_charged READ watt_hours_charged NOTIFY watt_hours_chargedChanged)
    Q_PROPERTY(float temp_mos1 READ temp_mos1 NOTIFY temp_mos1Changed)
    Q_PROPERTY(float temp_pcb READ temp_pcb NOTIFY temp_pcbChanged)
    Q_PROPERTY(float current_in READ current_in NOTIFY current_inChanged)
    Q_PROPERTY(float current_motor READ current_motor NOTIFY current_motorChanged)
    Q_PROPERTY(float duty READ duty NOTIFY dutyChanged)
public:
    explicit  TelemetryModel(QObject* parent = nullptr) {}

    float rpm() const {return m_rpm; }
    float speed() const {return m_speed; }
    float voltage() const {return m_voltage; }
    float amp_hours() const {return m_amp_hours; }
    float amp_hours_charged() const {return m_amp_hours_charged; }
    float watt_hours() const {return m_watt_hours; }
    float watt_hours_charged() const {return m_watt_hours_charged; }
    float temp_mos1() const {return m_temp_mos1; }
    float temp_pcb() const {return m_temp_pcb; }
    float current_in() const {return m_current_in; }
    float current_motor() const {return m_current_motor; }
    float duty() const {return m_duty; }

    void updateFrom(const mcu_can_frame::mc_values& values) {
        setIfChanged(m_rpm, values.rpm, &TelemetryModel::rpmChanged);
        setIfChanged(m_speed, values.speed, &TelemetryModel::speedChanged);
        setIfChanged(m_voltage, values.v_in, &TelemetryModel::voltageChanged);
        setIfChanged(m_amp_hours, values.amp_hours, &TelemetryModel::amp_hoursChanged);
        setIfChanged(m_amp_hours_charged, values.amp_hours_charged, &TelemetryModel::amp_hours_chargedChanged);
        setIfChanged(m_watt_hours, values.watt_hours, &TelemetryModel::watt_hoursChanged);
        setIfChanged(m_watt_hours_charged, values.watt_hours_charged, &TelemetryModel::watt_hours_chargedChanged);
        setIfChanged(m_temp_mos1, values.temp_mos1, &TelemetryModel::temp_mos1Changed);
        setIfChanged(m_temp_pcb, values.temp_pcb, &TelemetryModel::temp_pcbChanged);
        setIfChanged(m_current_in, values.current_in, &TelemetryModel::current_inChanged);
        setIfChanged(m_current_motor,values.current_motor, &TelemetryModel::current_motorChanged);
        setIfChanged(m_duty, values.duty_now, &TelemetryModel::dutyChanged);
    }

    signals:
    void rpmChanged();
    void speedChanged();
    void voltageChanged();
    void amp_hoursChanged();
    void amp_hours_chargedChanged();
    void watt_hoursChanged();
    void watt_hours_chargedChanged();
    void temp_mos1Changed();
    void temp_pcbChanged();
    void current_inChanged();
    void current_motorChanged();
    void dutyChanged();

private:
    float m_rpm = 0;
    float m_speed = 0;
    float m_voltage = 0;
    float m_amp_hours = 0;
    float m_amp_hours_charged = 0;
    float m_watt_hours = 0;
    float m_watt_hours_charged = 0;
    float m_temp_mos1 = 0;
    float m_temp_pcb = 0;
    float m_current_in = 0;
    float m_current_motor = 0;
    float m_duty = 0;

    template<typename T, typename  Signal>
    void setIfChanged(T& member, T newValue, Signal signal) {
        if (member != newValue) {
            member = newValue;
            emit (this->*signal)();
        }
    }
};



#endif //TELEMETRYMODEL_H
