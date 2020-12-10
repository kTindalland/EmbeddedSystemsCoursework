cmake_minimum_required(VERSION 3.13.4)


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
