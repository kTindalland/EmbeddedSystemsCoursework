cmake_minimum_required(VERSION 3.13.4)


add_subdirectory(googletest)

include_directories(../MPLAB_Project)
set(Headers
    ../MPLAB_Project/RealTimeClockConversions.h
)

set(Sources 
    ../MPLAB_Project/RealTimeClockConversions.c
)

add_compile_definitions(__UNIT_TESTING)

add_library(SmartHeaterLogicalCode STATIC ${Sources} ${Headers})

add_library(StringUtilsCode STATIC ../MPLAB_Project/StringUtils.h ../MPLAB_Project/StringUtils.c ../MPLAB_Project/NumberConverter.h ../MPLAB_Project/NumberConverter.c)

add_library(ThermometerCode STATIC ../MPLAB_Project/ThermometerDriver.h ../MPLAB_Project/ThermometerInterface.h ../MPLAB_Project/ThermometerInterface.c)

add_subdirectory(unit_tests)
