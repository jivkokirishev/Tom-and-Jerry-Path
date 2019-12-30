//
// Created by jivko on 14.12.19.
//

#ifndef TOM_AND_JERRY_PATH_PATH_H
#define TOM_AND_JERRY_PATH_PATH_H


#include <list>
#include "Point.h"
#include "Step.h"
#include "PathIterator.h"

class Path {
public:
    void addStep(Point step);
    void constructPathFromReversedSteps(Step* reversedSteps);
    PathIterator getIterator();

private:
    std::list<Point> steps;
};


#endif //TOM_AND_JERRY_PATH_PATH_H
