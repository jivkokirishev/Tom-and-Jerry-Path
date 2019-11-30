//
// Created by jivko on 30.11.19.
//

#ifndef TOM_AND_JERRY_PATH_PATHSFINDER_H
#define TOM_AND_JERRY_PATH_PATHSFINDER_H


#include <stack>
#include "RoomModel.h"
#include "Step.h"

class PathsFinder {
public:
    PathsFinder(RoomModel model);

    std::vector<std::stack<Point>> bfsPaths(int maxPaths = 1);


private:
    RoomModel model;

    bool isVisited(Step* currentPath, Point position);

    void newStepPush(std::queue<Step*>& paths, Step *currentStep, int horizontalShift, int verticalShift);
};


#endif //TOM_AND_JERRY_PATH_PATHSFINDER_H
