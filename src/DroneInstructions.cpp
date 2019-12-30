//
// Created by jivko on 04.12.19.
//

#include "DroneInstructions.h"

DroneInstructions::DroneInstructions(Path path, std::list<std::string> instructions,
                                     std::list<Point> placesToPaint, unsigned int turnCount, unsigned int stepsCount) :
        pathCoordinates(path), instructions(instructions),
        placesToPaint(placesToPaint), turnCount(turnCount), stepsCount(stepsCount) {
}

Path &DroneInstructions::getPathCoordinates() {
    return pathCoordinates;
}

const std::list<std::string> &DroneInstructions::getDirections() const {
    return instructions;
}

const std::list<Point> &DroneInstructions::getPlacesToPaint() const {
    return placesToPaint;
}

unsigned int DroneInstructions::getTurnCount() const {
    return turnCount;
}

unsigned int DroneInstructions::getMaxPaintPlaces() const {
    return  placesToPaint.size();
}

unsigned int DroneInstructions::getStepsCount() const {
    return stepsCount;
}
