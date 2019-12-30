//
// Created by jivko on 30.11.19.
//

#include "Step.h"

Step::Step(Point position) : position(position), previousStep(nullptr){
}

Step::Step(Point position, Step* previousStep) : position(position), previousStep(previousStep){
}

Step::Step(int x, int y, Step* previousStep) : position(Point(x, y)), previousStep(previousStep){
}

const Point &Step::getPosition() const {
    return position;
}

Step *Step::getPreviousStep() const {
    return previousStep;
}
