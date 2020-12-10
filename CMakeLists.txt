cmake_minimum_required(VERSION 3.13.4)

project(SmartHeaterTesting)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(unit_testing)
