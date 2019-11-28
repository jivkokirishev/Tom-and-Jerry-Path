//
// Created by jivko on 13.11.19.
//

#ifndef TOM_AND_JERRY_PATH_MAIN_CPP
#define TOM_AND_JERRY_PATH_MAIN_CPP

#include <iostream>
#include <fstream>
#include <string>
#include "FileExtractor.h"
#include "RoomModel.h"

int main() {

    FileExtractor streamParser("./src/instructions.txt");

    RoomModel room(RawRoomModel(streamParser.extractRawFile()));

    for (int i = 0; i < room.getRoom().size(); ++i) {
        std::cout << room.getRoom()[i] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}


#endif //TOM_AND_JERRY_PATH_MAIN_CPP
