cmake_minimum_required(VERSION 3.13.4)

include_directories(../../MPLAB_Project)
add_executable(SmartHeaterUnitTests main.cpp)

target_link_libraries(SmartHeaterUnitTests PUBLIC 
    gtest_main
    SmartHeaterLogicalCode
)

add_test(
    NAME SmartHeaterUnitTests
    COMMAND SmartHeaterUnitTests
)
