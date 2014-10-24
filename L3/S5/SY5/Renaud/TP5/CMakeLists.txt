cmake_minimum_required(VERSION 2.8.4)
project(TP5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES myLittleCat.c)
add_executable(TP5 ${SOURCE_FILES})