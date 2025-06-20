cmake_minimum_required(VERSION 3.25.1)
project(RideFlow)

set(CMAKE_CXX_STANDARD 20)

add_executable(RideFlow Rideflow.cpp
        conn_can/can.cpp
        conn_can/can.h
        conn_can/mcu_can_frame.cpp
        conn_can/mcu_can_frame.h
)
