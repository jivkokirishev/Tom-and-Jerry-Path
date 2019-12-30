//
// Created by jivko on 04.12.19.
//

#ifndef TOM_AND_JERRY_PATH_INSTRUCTIONSBUILDER_H
#define TOM_AND_JERRY_PATH_INSTRUCTIONSBUILDER_H


#include "DroneInstructions.h"
#include "RoomModel.h"
#include "Path.h"

class InstructionsBuilder {
public:
    InstructionsBuilder(RoomModel room);

    DroneInstructions createInstructionsByPath(Path path);

private:
    RoomModel room;

    std::list<std::string> generateInstructions(Path path);
    std::list<Point> generatePlacesToPaint(Path path);
    unsigned int countTurns(std::list<std::string> instructions);
    unsigned int countSteps(std::list<std::string> instructions);
    void appendStats(std::list<std::string> &instructions, unsigned int stepsCount, unsigned int paintCount, unsigned int turnsCount);


    std::string findTurn(Point currentPoint, Point nextPoint);
    bool canBePainted(Point coordinates);
};


#endif //TOM_AND_JERRY_PATH_INSTRUCTIONSBUILDER_H
