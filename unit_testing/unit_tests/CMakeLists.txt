cmake_minimum_required(VERSION 3.13.4)

add_executable(SmartHeaterUnitTests main.cpp)

target_link_libraries(SmartHeaderUnitTests PUBLIC 
    gtest_main
    SmartHeaterLogicalCode
)

add_test(
    NAME SmartHeaderUnitTests
    COMMAND SmartHeaderUnitTests
)