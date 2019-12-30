//
// Created by jivko on 29.12.19.
//

#include "TwoDroneInstructions.h"

const DroneInstructions &TwoDroneInstructions::getFirstDrone() const {
    return firstDrone;
}

const DroneInstructions &TwoDroneInstructions::getSecondDrone() const {
    return secondDrone;
}

unsigned int TwoDroneInstructions::getMaxPaintPlaces() const {
    return maxPaintPlaces;
}

TwoDroneInstructions::TwoDroneInstructions(DroneInstructions firstDrone, DroneInstructions secondDrone,
                                           unsigned int maxPaintPlaces) : firstDrone(firstDrone), secondDrone(secondDrone), maxPaintPlaces(maxPaintPlaces) {
}

void TwoDroneInstructions::setFirstDrone(const DroneInstructions &firstDrone) {
    TwoDroneInstructions::firstDrone = firstDrone;
}

void TwoDroneInstructions::setSecondDrone(const DroneInstructions &secondDrone) {
    TwoDroneInstructions::secondDrone = secondDrone;
}

void TwoDroneInstructions::setMaxPaintPlaces(unsigned int maxPaintPlaces) {
    TwoDroneInstructions::maxPaintPlaces = maxPaintPlaces;
}
