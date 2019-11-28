//
// Created by jivko on 14.11.19.
//

#include "Point.h"

Point::Point() : x(0), y(0){
}

Point::Point(std::string coordinates) {
    std::string delimiter = " ";
    std::string width = coordinates.substr(0, coordinates.find(delimiter));
    std::string length = coordinates.substr(coordinates.find(delimiter) + 1, coordinates.length());

    x = std::stoi(width);
    y = std::stoi(length);
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}
