//
// Created by jivko on 14.12.19.
//

#include <algorithm>
#include "Node.h"
#include "Utility.h"

Node::Node(char data) : data(data) {
}

char Node::getData() const {
    return data;
}

const std::vector<Node *> &Node::getChildren() const {
    return children;
}

void Node::addBranch(std::list<char> instructions) {
    auto instructIter = instructions.begin();

    Node *currentNode = this;
    ++instructIter;

    while (instructIter != instructions.end()) {
        Node *wantedChild = Utility::doesInstructionExist(currentNode->children, *instructIter);
        if (wantedChild == nullptr) {
            currentNode->children.push_back(new Node(*instructIter));
            currentNode = currentNode->children.back();
        } else {
            currentNode = wantedChild;
        }
        ++instructIter;
    }
}

