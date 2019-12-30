//
// Created by jivko on 14.11.19.
//

#ifndef TOM_AND_JERRY_PATH_FURNITURE_H
#define TOM_AND_JERRY_PATH_FURNITURE_H


#include <string>
#include <vector>
#include "Point.h"

class Furniture {
public:
    Furniture(Point startingPoint, std::vector<std::string> furnitureMap);

private:
    Point startingPoint;
    std::vector<std::string> furnitureMap;
public:
    const Point &getStartingPoint() const;

    const std::vector<std::string> &getFurnitureMap() const;

};


#endif //TOM_AND_JERRY_PATH_FURNITURE_H
