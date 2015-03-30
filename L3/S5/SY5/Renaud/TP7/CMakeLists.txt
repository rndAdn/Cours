cmake_minimum_required(VERSION 2.8.4)
project(TP7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(TP7 ${SOURCE_FILES})