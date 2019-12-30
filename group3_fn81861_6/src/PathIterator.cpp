//
// Created by jivko on 14.12.19.
//

#include "PathIterator.h"

PathIterator::PathIterator(std::list<Point, std::allocator<Point>>::iterator pathIter,
        std::list<Point, std::allocator<Point>>::iterator pathEnd)
        : pathIter(pathIter), pathEnd(pathEnd){
}

void PathIterator::next() {
    ++pathIter;
}

Point PathIterator::get() {
    return *pathIter;
}

bool PathIterator::valid() {
    return pathIter !=  pathEnd;
}
