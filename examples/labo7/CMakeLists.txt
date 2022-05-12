cmake_minimum_required(VERSION 3.10)
project(unittest)
SET(CMAKE_CXX_STANDARD 11)

include_directories(src)
include_directories(test)
add_subdirectory(src)
add_subdirectory(test)