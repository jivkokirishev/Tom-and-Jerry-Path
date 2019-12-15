//
// Created by jivko on 14.12.19.
//

#include "Utility.h"

Node *Utility::doesInstructionExist(std::vector<Node *> instructions, char instruction) {
    for (auto it = instructions.begin(); it != instructions.end(); ++it) {
        if((*it)->getData() == instruction){
            return *it;
        }
    }

    return nullptr;
}
