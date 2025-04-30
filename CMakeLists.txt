cmake_minimum_required(VERSION 3.25.1)
project(RideFlow)

set(CMAKE_CXX_STANDARD 20)

add_executable(RideFlow Rideflow.cpp
        opensocket.cpp
        opensocket.h
        readcan.cpp
        readcan.h
)
