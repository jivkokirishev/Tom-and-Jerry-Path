//
// Created by jivko on 14.12.19.
//

#ifndef TOM_AND_JERRY_PATH_UTILITY_H
#define TOM_AND_JERRY_PATH_UTILITY_H


#include <vector>
#include "Node.h"

class Utility {
public:
    static Node *doesInstructionExist(std::vector<Node*> instructions, char instruction);

};


#endif //TOM_AND_JERRY_PATH_UTILITY_H
