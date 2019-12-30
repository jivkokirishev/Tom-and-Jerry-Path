//
// Created by jivko on 14.12.19.
//

#ifndef TOM_AND_JERRY_PATH_NODE_H
#define TOM_AND_JERRY_PATH_NODE_H

#include <list>
#include <vector>
#include "Point.h"

class Node {
public:
    Node(char data);
    void addBranch(std::list<char> instructions);

private:
    char data;
public:
    char getData() const;

    const std::vector<Node *> &getChildren() const;

private:
    std::vector<Node*> children;
};


#endif //TOM_AND_JERRY_PATH_NODE_H
