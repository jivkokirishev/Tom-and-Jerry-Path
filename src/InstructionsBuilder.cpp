//
// Created by jivko on 04.12.19.
//

#include "InstructionsBuilder.h"

InstructionsBuilder::InstructionsBuilder(RoomModel room) : room(room) {
}

DroneInstructions InstructionsBuilder::createInstructionsByPath(std::stack<Point> path) {
    auto pathCoordinates = generatePath(path);
    auto instructions = generateInstructions(pathCoordinates);
    auto paintCoordinates = generatePlacesToPaint(path);
    unsigned int turnsCount = countTurns(instructions);


    DroneInstructions droneInstructions(paintCoordinates, instructions, paintCoordinates, turnsCount);

    return droneInstructions;
}

std::list<Point> InstructionsBuilder::generatePath(std::stack<Point> path) {
    std::list<Point> listPath;

    while (!path.empty()) {
        listPath.push_back(path.top());
        path.pop();
    }

    return listPath;
}

std::list<char> InstructionsBuilder::generateInstructions(std::list<Point> path) {
    std::list<char> instructions;

    instructions.push_back('B');
    auto pathIter = path.begin();
    auto beforeLast = --(path.end());
    while (pathIter != beforeLast) {
        Point currentPoint = *pathIter;
        Point nextPoint = *(++pathIter);
        instructions.push_back(findTurn(currentPoint, nextPoint));
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

std::list<Point> InstructionsBuilder::generatePlacesToPaint(std::stack<Point> path) {
    std::list<Point> placesToPaint;

    while (!path.empty()) {
        if (canBePainted(path.top())) {
            placesToPaint.push_back(path.top());
        }
        path.pop();
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
