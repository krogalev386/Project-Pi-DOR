cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
project(gpio_contron_test)

include(ExternalProject)

add_subdirectory(gpiod)
add_subdirectory(src)
