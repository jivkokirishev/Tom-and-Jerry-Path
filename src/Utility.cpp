//
// Created by jivko on 14.12.19.
//

#include <algorithm>
#include "Utility.h"

Node *Utility::doesInstructionExist(std::vector<Node *> instructions, std::string instruction) {
    for (auto it = instructions.begin(); it != instructions.end(); ++it) {
        if((*it)->getData() == instruction){
            return *it;
        }
    }

    return nullptr;
}

DroneInstructions const *Utility::getMaxPaintingInstructions(std::vector<DroneInstructions> const &instructions) {
    DroneInstructions const *bestInstructions = &instructions.front();

    for (int i = 1; i < instructions.size(); ++i) {
        if(bestInstructions->getMaxPaintPlaces() < instructions[i].getMaxPaintPlaces()){
            bestInstructions = &instructions[i];
        } else if (bestInstructions->getMaxPaintPlaces() == instructions[i].getMaxPaintPlaces()
                   && instructions[i].getTurnCount() < bestInstructions->getTurnCount()){
            bestInstructions = &instructions[i];
        }
    }

    return bestInstructions;
}

TwoDroneInstructions Utility::get2PaintingInstructions(std::vector<DroneInstructions> const &instructions) {

    std::map<unsigned int, std::vector<DroneInstructions>*> instructionsByStepsCount;

    for (int i = 0; i < instructions.size(); ++i) {
        unsigned int steps = instructions[i].getStepsCount();
        std::vector<DroneInstructions> *currentInstructions;

        if(instructionsByStepsCount.find(steps) == instructionsByStepsCount.end()){
            currentInstructions = new std::vector<DroneInstructions>();
            currentInstructions->push_back(instructions[i]);
            instructionsByStepsCount.insert(std::pair<unsigned int, std::vector<DroneInstructions>*>(steps, currentInstructions));
        } else{
            currentInstructions = instructionsByStepsCount.at(instructions[i].getStepsCount());
            currentInstructions->push_back(instructions[i]);
        }
    }

    std::vector<TwoDroneInstructions> twoDronesVector = reduceInstructions(instructionsByStepsCount);

    return *takeWithMaxPainting(twoDronesVector);
}

std::vector<TwoDroneInstructions>
Utility::reduceInstructions(std::map<unsigned int, std::vector<DroneInstructions> *> const &groupedBySteps) {
    std::vector<TwoDroneInstructions> reducedInstructions;

    auto iter = groupedBySteps.begin();
    for (;iter != groupedBySteps.end(); ++iter) {

        TwoDroneInstructions twoDrones(iter->second->front(), iter->second->back(), iter->second->front().getMaxPaintPlaces());

        for (int i = 0; i < iter->second->size(); ++i) {

            auto firstDrone = (*iter->second)[i].getPlacesToPaint();
            for (int j = i + 1; j < iter->second->size(); ++j) {
                auto secondDrone = (*iter->second)[j].getPlacesToPaint();
                unsigned int additionalPaint = 0;
                for (auto drIter = secondDrone.begin(); drIter != secondDrone.end(); ++drIter) {
                    auto samePaintPlace = std::find(firstDrone.begin(), firstDrone.end(), *drIter);
                    if(samePaintPlace == firstDrone.end()){
                        ++additionalPaint;
                    }
                }
                if (twoDrones.getMaxPaintPlaces() < (*iter->second)[i].getMaxPaintPlaces() + additionalPaint){
                    twoDrones.setFirstDrone((*iter->second)[i]);
                    twoDrones.setSecondDrone((*iter->second)[j]);
                    twoDrones.setMaxPaintPlaces((*iter->second)[i].getMaxPaintPlaces() + additionalPaint);
                }
            }
        }

        reducedInstructions.push_back(twoDrones);
    }


    return reducedInstructions;
}

TwoDroneInstructions const *Utility::takeWithMaxPainting(std::vector<TwoDroneInstructions> const &instructions) {


    TwoDroneInstructions const *maxPainting = &instructions.front();

    for (int i = 1; i < instructions.size(); ++i) {
        if (maxPainting->getMaxPaintPlaces() < instructions[i].getMaxPaintPlaces()
            || (maxPainting->getMaxPaintPlaces() == instructions[i].getMaxPaintPlaces()
                && instructions[i].getFirstDrone().getStepsCount() < maxPainting->getFirstDrone().getStepsCount())){
            maxPainting = &instructions[i];
        }
    }

    return maxPainting;
}


/*|| (twoDrones.getMaxPaintPlaces() == (*iter->second)[i].getMaxPaintPlaces() + additionalPaint
                        && (*iter->second)[i].getStepsCount() < twoDrones.getFirstDrone().getStepsCount())*/