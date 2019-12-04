//
// Created by jivko on 04.12.19.
//

#ifndef TOM_AND_JERRY_PATH_INSTRUCTIONSBUILDER_H
#define TOM_AND_JERRY_PATH_INSTRUCTIONSBUILDER_H


#include "DroneInstructions.h"
#include "RoomModel.h"

class InstructionsBuilder {
public:
    InstructionsBuilder(RoomModel room);

    DroneInstructions createInstructionsByPath(std::stack<Point> path);

private:
    RoomModel room;

    std::list<Point> generatePath(std::stack<Point> path);
    std::list<char> generateInstructions(std::list<Point> path);
    std::list<Point> generatePlacesToPaint(std::stack<Point> path);
    unsigned int countTurns(std::list<char> instructions);

    char findTurn(Point currentPoint, Point nextPoint);
    bool canBePainted(Point coordinates);
};


#endif //TOM_AND_JERRY_PATH_INSTRUCTIONSBUILDER_H
