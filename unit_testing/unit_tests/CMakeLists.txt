cmake_minimum_required(VERSION 3.13.4)

include_directories(../../MPLAB_Project)

add_executable(SmartHeaterUnitTests RTC_Tests.cpp)
add_executable(ThermometerUnitTests Thermometer_Tests.cpp)

target_link_libraries(SmartHeaterUnitTests PUBLIC 
    gtest_main
    SmartHeaterLogicalCode
)

target_link_libraries(ThermometerUnitTests PUBLIC
    gtest_main
    ThermometerCode
)

add_test(
    NAME SmartHeaterUnitTests
    COMMAND SmartHeaterUnitTests
)

add_test(
    NAME ThermometerUnitTests
    COMMAND ThermometerUnitTests
)
