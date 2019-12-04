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
#include "Step.h"
#include "PathsFinder.h"
#include "InstructionsBuilder.h"

int main() {

    FileExtractor streamParser("./src/instructions.txt");

    RoomModel room(RawRoomModel(streamParser.extractRawFile()));

    for (int i = 0; i < room.getRoom().size(); ++i) {
        std::cout << room.getRoom()[i] << std::endl;
    }

    std::cout << std::endl;

    PathsFinder pathsFinder(room);

    InstructionsBuilder builder(room);

    for(std::stack<Point> path : pathsFinder.bfsPaths(9)){
        auto instructions = builder.createInstructionsByPath(path);
        for (auto direction : instructions.getDirections()) {
            std::cout << direction << "  ";
        }

        std::cout << instructions.getTurnCount() << "  ";
        std::cout << instructions.getPlacesToPaint().size();
        std::cout << std::endl << std::endl;
    }


    return 0;
}


#endif //TOM_AND_JERRY_PATH_MAIN_CPP
