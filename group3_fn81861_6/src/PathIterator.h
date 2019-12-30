//
// Created by jivko on 14.12.19.
//

#ifndef TOM_AND_JERRY_PATH_PATHITERATOR_H
#define TOM_AND_JERRY_PATH_PATHITERATOR_H


#include <list>
#include "Point.h"

class PathIterator {
public:
    PathIterator(std::list<Point, std::allocator<Point>>::iterator pathIter, std::list<Point, std::allocator<Point>>::iterator pathEnd);
    void next();
    Point get();
    bool valid();

private:
    std::list<Point, std::allocator<Point>>::iterator pathIter;
    std::list<Point, std::allocator<Point>>::iterator pathEnd;
};


#endif //TOM_AND_JERRY_PATH_PATHITERATOR_H
