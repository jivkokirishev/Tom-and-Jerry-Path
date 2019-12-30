//
// Created by jivko on 14.11.19.
//

#include "Furniture.h"

Furniture::Furniture(Point startingPoint, std::vector<std::string> furnitureMap) : startingPoint(startingPoint), furnitureMap(furnitureMap){
}

const Point &Furniture::getStartingPoint() const {
    return startingPoint;
}

const std::vector<std::string> &Furniture::getFurnitureMap() const {
    return furnitureMap;
}
