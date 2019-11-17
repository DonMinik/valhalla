cmake_minimum_required(VERSION 3.15)
project(valhalla)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_executable(valhalla src/main.cpp)

target_link_libraries(valhalla ${SDL2_LIBRARIES} )






