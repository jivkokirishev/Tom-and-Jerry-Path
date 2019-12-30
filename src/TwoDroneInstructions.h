//
// Created by jivko on 29.12.19.
//

#ifndef TOM_AND_JERRY_PATH_TWODRONEINSTRUCTIONS_H
#define TOM_AND_JERRY_PATH_TWODRONEINSTRUCTIONS_H


#include "DroneInstructions.h"

class TwoDroneInstructions {
public:
    TwoDroneInstructions(DroneInstructions firstDrone, DroneInstructions secondDrone, unsigned int maxPaintPlaces);

    void setFirstDrone(const DroneInstructions &firstDrone);

    void setSecondDrone(const DroneInstructions &secondDrone);

    void setMaxPaintPlaces(unsigned int maxPaintPlaces);

    const DroneInstructions &getFirstDrone() const;

    const DroneInstructions &getSecondDrone() const;

    unsigned int getMaxPaintPlaces() const;

private:
    DroneInstructions firstDrone;
    DroneInstructions secondDrone;
    unsigned int maxPaintPlaces;
};


#endif //TOM_AND_JERRY_PATH_TWODRONEINSTRUCTIONS_H
