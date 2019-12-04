//
// Created by jivko on 04.12.19.
//

#include "DroneInstructions.h"

DroneInstructions::DroneInstructions(std::list<Point> path, std::list<char> instructions,
                                     std::list<Point> placesToPaint, unsigned int turnCount) :
        pathCoordinates(path), instructions(instructions),
        placesToPaint(placesToPaint), turnCount(turnCount) {
}

const std::list<Point> &DroneInstructions::getPathCoordinates() const {
    return pathCoordinates;
}

const std::list<char> &DroneInstructions::getDirections() const {
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
