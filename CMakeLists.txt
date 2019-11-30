cmake_minimum_required(VERSION 3.14)
project(Tom_and_Jerry_Path)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(Tom_and_Jerry_Path
        src/main.cpp
        src/FileExtractor.cpp
        src/FileExtractor.h
        src/Furniture.cpp
        src/Furniture.h
        src/Point.cpp
        src/Point.h
        src/RawRoomModel.cpp
        src/RawRoomModel.h
        src/RoomModel.cpp
        src/RoomModel.h
        src/PathsFinder.cpp
        src/PathsFinder.h
        src/Step.cpp
        src/Step.h)
