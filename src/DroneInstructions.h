//
// Created by jivko on 04.12.19.
//

#ifndef TOM_AND_JERRY_PATH_DRONEINSTRUCTIONS_H
#define TOM_AND_JERRY_PATH_DRONEINSTRUCTIONS_H

#include <list>
#include <stack>
#include "Point.h"
#include "Path.h"

class DroneInstructions {
public:
    DroneInstructions(Path path, std::list<std::string> instructions,
                      std::list<Point> placesToPaint, unsigned int turnCount, unsigned int stepsCount);

    Path &getPathCoordinates();

    const std::list<std::string> &getDirections() const;

    const std::list<Point> &getPlacesToPaint() const;

    unsigned int getTurnCount() const;

    unsigned int getMaxPaintPlaces() const;

    unsigned int getStepsCount() const;

private:
    Path pathCoordinates;
    std::list<std::string> instructions;
    std::list<Point> placesToPaint;
    unsigned int turnCount;
    unsigned int stepsCount;
};


#endif //TOM_AND_JERRY_PATH_DRONEINSTRUCTIONS_H
