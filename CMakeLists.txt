cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
project(Pi-DOR)

include(ExternalProject)

add_subdirectory(robot)
add_subdirectory(gpiod)
add_subdirectory(src)
