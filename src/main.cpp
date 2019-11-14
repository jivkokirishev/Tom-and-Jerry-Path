//
// Created by jivko on 13.11.19.
//

#ifndef TOM_AND_JERRY_PATH_MAIN_CPP
#define TOM_AND_JERRY_PATH_MAIN_CPP

#include <iostream>
#include <fstream>
#include <string>
#include "StreamParser.h"

int main() {

    StreamParser streamParser("./src/instructions.txt");



    std::cout << streamParser.getPaintPermissionedBlocks()[0][0];

    return 0;
}


#endif //TOM_AND_JERRY_PATH_MAIN_CPP
