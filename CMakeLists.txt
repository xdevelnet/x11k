cmake_minimum_required(VERSION 3.2)
project(x11k)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES
    x11k.c utils.h defaults.h x11routines.h shmemroutines.h)

add_executable(x11k ${SOURCE_FILES})
