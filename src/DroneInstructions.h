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
    DroneInstructions(Path path, std::list<char> instructions,
                      std::list<Point> placesToPaint, unsigned int turnCount);

    const Path &getPathCoordinates() const;

    const std::list<char> &getDirections() const;

    const std::list<Point> &getPlacesToPaint() const;

    unsigned int getTurnCount() const;

    unsigned int getMaxPaintPlaces() const;

private:
    Path pathCoordinates;
    std::list<char> instructions;
    std::list<Point> placesToPaint;
    unsigned int turnCount;
};


#endif //TOM_AND_JERRY_PATH_DRONEINSTRUCTIONS_H
