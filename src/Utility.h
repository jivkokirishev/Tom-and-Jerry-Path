//
// Created by jivko on 14.12.19.
//

#ifndef TOM_AND_JERRY_PATH_UTILITY_H
#define TOM_AND_JERRY_PATH_UTILITY_H


#include <vector>
#include <map>
#include "Node.h"
#include "DroneInstructions.h"
#include "TwoDroneInstructions.h"

class Utility {
public:
    static Node *doesInstructionExist(std::vector<Node*> instructions, std::string instruction);

    static DroneInstructions const *getMaxPaintingInstructions(std::vector<DroneInstructions> const &instructions);

    static TwoDroneInstructions get2PaintingInstructions(std::vector<DroneInstructions> const &instructions);

private:
    static std::vector<TwoDroneInstructions> reduceInstructions(std::map<unsigned int, std::vector<DroneInstructions>*> const &groupedBySteps);

    static TwoDroneInstructions const *takeWithMaxPainting(std::vector<TwoDroneInstructions> const &instructions);
};


#endif //TOM_AND_JERRY_PATH_UTILITY_H
