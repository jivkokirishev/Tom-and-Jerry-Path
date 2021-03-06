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
    Node(std::string data);
    void addBranch(std::list<std::string> instructions);

private:
    std::string data;
public:
    std::string getData() const;

    const std::vector<Node *> &getChildren() const;

private:
    std::vector<Node*> children;
};


#endif //TOM_AND_JERRY_PATH_NODE_H
