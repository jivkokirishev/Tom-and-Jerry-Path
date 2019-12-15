//
// Created by jivko on 14.12.19.
//

#ifndef TOM_AND_JERRY_PATH_INSTRUCTIONSTREE_H
#define TOM_AND_JERRY_PATH_INSTRUCTIONSTREE_H


#include <iostream>
#include <string>
#include "Node.h"

class InstructionsTree {
public:
    InstructionsTree(Node *tree);

    void dottyPrint(std::ostream& out);

private:
    Node *tree;

    void dottyPrintHelp (std::ostream& out, Node *current);
};


#endif //TOM_AND_JERRY_PATH_INSTRUCTIONSTREE_H
