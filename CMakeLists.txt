cmake_minimum_required(VERSION 3.14)
project(Tom_and_Jerry_Path)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(Tom_and_Jerry_Path
        src/main.cpp)
