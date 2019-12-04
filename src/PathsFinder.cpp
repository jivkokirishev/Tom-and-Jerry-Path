//
// Created by jivko on 30.11.19.
//

#include "PathsFinder.h"

PathsFinder::PathsFinder(RoomModel model) : model(model){
}

std::vector<std::stack<Point>> PathsFinder::bfsPaths(int maxPaths) {
    std::queue<Step*> paths;

    Step *tom = new Step(model.getTomPosition());
    paths.push(tom);

    Point jerryPosition = model.getJerryPosition();

    std::vector<std::stack<Point>> shortestPaths;

    while(!paths.empty() && shortestPaths.size() < maxPaths)
    {
        Step *currentPath = paths.front();
        paths.pop();

        if(currentPath->getPosition() == jerryPosition)
        {
            std::stack<Point> path;

            while (currentPath != nullptr){
                path.push(currentPath->getPosition());
                currentPath = currentPath->getPreviousStep();
            }

            shortestPaths.push_back(path);
        } else{
            for(int i : {-1, 1}){
                newStepPush(paths, currentPath, i, 0);
                newStepPush(paths, currentPath, 0, i);
            }
        }

    }


    return shortestPaths;
}

bool PathsFinder::isVisited(Step *currentPath, Point position) {
    Step* pathsPositions = currentPath;

    while (pathsPositions != nullptr){
        if(position == pathsPositions->getPosition()){
            return true;
        }
        pathsPositions = pathsPositions->getPreviousStep();
    }

    return false;
}

void PathsFinder::newStepPush(std::queue<Step *> &paths, Step *currentPath, int horizontalShift, int verticalShift) {

    Point shiftedPosition = Point(currentPath->getPosition().getX() + horizontalShift, currentPath->getPosition().getY() + verticalShift);

    if(!isVisited(currentPath, shiftedPosition) &&
        model.getRoom()[shiftedPosition.getY() + model.WALLS_OFFSET][shiftedPosition.getX() + model.WALLS_OFFSET] != '1'){

        Step* newStep = new Step(shiftedPosition, currentPath);
        paths.push(newStep);
    }
}
