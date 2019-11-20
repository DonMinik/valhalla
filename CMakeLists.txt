cmake_minimum_required(VERSION 3.15)
project(valhalla)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS}  ${SDL2_IMAGE_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 17)

add_executable(valhalla
        src/main.cpp
        src/visual/sprite.cpp
        src/visual/view.cpp
        src/visual/view-controller.cpp
        src/visual/events/input.cpp
        src/control/game.cpp
        )

target_link_libraries(valhalla ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

message(${SDL2_IMAGE_FOUND})




