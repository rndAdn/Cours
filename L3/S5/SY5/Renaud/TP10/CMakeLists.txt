cmake_minimum_required(VERSION 2.8.4)
project(TP10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gcc")

set(SOURCE_FILES main.c)
add_executable(TP10 ${SOURCE_FILES})