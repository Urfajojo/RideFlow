cmake_minimum_required(VERSION 3.25.1)
project(RideFlow)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

add_executable(RideFlow Rideflow.cpp
        conn_can/can.cpp
        conn_can/can.h
        conn_can/mcu_can_frame.cpp
        conn_can/mcu_can_frame.h
        MainWindow.qml
)

target_link_libraries(RideFlow
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
)

