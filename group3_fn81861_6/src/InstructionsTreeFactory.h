//
// Created by jivko on 14.12.19.
//

#ifndef TOM_AND_JERRY_PATH_INSTRUCTIONSTREEFACTORY_H
#define TOM_AND_JERRY_PATH_INSTRUCTIONSTREEFACTORY_H


#include "DroneInstructions.h"
#include "InstructionsTree.h"

class InstructionsTreeFactory {
public:
    InstructionsTree createTree(std::vector<DroneInstructions> droneInstruciotns);

};


#endif //TOM_AND_JERRY_PATH_INSTRUCTIONSTREEFACTORY_H
