//
// Created by jivko on 14.12.19.
//

#include "InstructionsTreeFactory.h"

InstructionsTree InstructionsTreeFactory::createTree(std::vector<DroneInstructions> droneInstructions) {

    Node *tree = new Node(droneInstructions.front().getDirections().front());

    for (auto elem : droneInstructions) {
        tree->addBranch(elem.getDirections());
    }

    return InstructionsTree(tree);
}
