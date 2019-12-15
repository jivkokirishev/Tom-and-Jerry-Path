//
// Created by jivko on 04.12.19.
//

#include "InstructionsBuilder.h"

InstructionsBuilder::InstructionsBuilder(RoomModel room) : room(room) {
}

DroneInstructions InstructionsBuilder::createInstructionsByPath(Path path) {
    auto instructions = generateInstructions(path);
    auto paintCoordinates = generatePlacesToPaint(path);
    unsigned int turnsCount = countTurns(instructions);


    DroneInstructions droneInstructions(path, instructions, paintCoordinates, turnsCount);

    return droneInstructions;
}

std::list<char> InstructionsBuilder::generateInstructions(Path path) {
    std::list<char> instructions;

    instructions.push_back('B');
    auto pathIter = path.getIterator();
    while (pathIter.valid()) {
        Point currentPoint = pathIter.get();
        pathIter.next();
        if(pathIter.valid()){
            Point nextPoint = pathIter.get();
            instructions.push_back(findTurn(currentPoint, nextPoint));
        }
    }
    instructions.push_back('F');

    return instructions;
}

char InstructionsBuilder::findTurn(Point currentPoint, Point nextPoint) {
    if (currentPoint.getX() + 1 == nextPoint.getX()) {
        return 'E';
    }
    if (currentPoint.getX() - 1 == nextPoint.getX()) {
        return 'W';
    }

    if (currentPoint.getY() + 1 == nextPoint.getY()) {
        return 'S';
    }

    if (currentPoint.getY() - 1 == nextPoint.getY()) {
        return 'N';
    }

    return 0;

}

std::list<Point> InstructionsBuilder::generatePlacesToPaint(Path path) {
    std::list<Point> placesToPaint;

    auto pathIter = path.getIterator();
    while (pathIter.valid()) {
        if (canBePainted(pathIter.get())) {
            placesToPaint.push_back(pathIter.get());
        }
        pathIter.next();
    }

    return placesToPaint;
}

bool InstructionsBuilder::canBePainted(Point coordinates) {

    for (Point paintCoordinate : room.getPaintBlocks()) {
        if (paintCoordinate == coordinates) {
            return true;
        }
    }

    return false;
}

unsigned int InstructionsBuilder::countTurns(std::list<char> instructions) {

    auto instructIter = instructions.begin();
    ++instructIter;

    unsigned int turnCount = 0;
    while (instructIter != instructions.end()) {
        if (*instructIter != *(++instructIter)) {
            turnCount++;
        }
    }
    turnCount -= 2;

    return turnCount;
}
