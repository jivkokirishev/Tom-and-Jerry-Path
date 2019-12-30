//
// Created by jivko on 14.12.19.
//

#include "Path.h"

void Path::addStep(Point step) {
    steps.push_back(step);
}

void Path::constructPathFromReversedSteps(Step *reversedSteps) {
    while (reversedSteps != nullptr){
        steps.push_front(reversedSteps->getPosition());
        reversedSteps = reversedSteps->getPreviousStep();
    }
}

PathIterator Path::getIterator() {
    return PathIterator(steps.begin(), steps.end());
}
