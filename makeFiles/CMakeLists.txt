cmake_minimum_required(VERSION 3.5)
project(SAS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Polynomial.cpp Polynomial.h)
add_executable(SAS ${SOURCE_FILES})