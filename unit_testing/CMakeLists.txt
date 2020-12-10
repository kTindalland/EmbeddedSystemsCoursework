cmake_minimum_required(VERSION 3.13.4)

project(SmartHeaterTesting)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

include_directories(../MPLAB_Project)
set(Headers
    ../MPLAB_Project/RealTimeClockConversions.h
)

set(Sources 
    ../MPLAB_Project/RealTimeClockConversions.c
)

add_library(SmartHeaterLogicalCode STATIC ${Sources} ${Headers})

add_subdirectory(unit_tests)
