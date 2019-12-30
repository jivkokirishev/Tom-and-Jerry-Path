//
// Created by jivko on 30.11.19.
//

#ifndef TOM_AND_JERRY_PATH_STEP_H
#define TOM_AND_JERRY_PATH_STEP_H

#include "Point.h"

class Step{
public:
    Step(Point position);

    Step(Point position, Step* previousStep);

    Step(int x, int y, Step* previousStep);

    const Point &getPosition() const;

    Step *getPreviousStep() const;

private:
    Point position;
    Step* previousStep;
};

#endif //TOM_AND_JERRY_PATH_STEP_H
