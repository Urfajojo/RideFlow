//
// Created by Owner on 4/30/2025.
//
#pragma once
#ifndef READCAN_H
#define READCAN_H
#include <cstdint>
#include <linux/can.h>
class ReadCan;
inline can_frame frame;
int readcan(can_frame);
int sendcan(can_frame);
#endif READCAN_H
