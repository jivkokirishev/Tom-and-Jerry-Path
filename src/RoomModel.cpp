//
// Created by jivko on 28.11.19.
//

#include "RoomModel.h"

RoomModel::RoomModel(RawRoomModel roomModel) : rawRoomModel(roomModel) {
}

void RoomModel::parseJerryPosition() {
    jerryPosition = Point(rawRoomModel.jerryCoordinates);

}

void RoomModel::parseTomPosition() {
    tomPosition = Point(rawRoomModel.tomCoordinates);
}

void RoomModel::parseFurnitures() {
    int furnitureNumber = Point(rawRoomModel.furnitureAndPaintBlocksNumber).getX();

    int furnitureCounter = 0;
    int lineCounter = 0;
    Point startingPoint;
    std::vector<std::string> furnitureMap;
    while(furnitureCounter < furnitureNumber){
        std::string line = rawRoomModel.furnituresAndPaintBlocks[lineCounter];

        if(lineCounter == 0 || rawRoomModel.furnituresAndPaintBlocks[lineCounter - 1] == "==="){

            startingPoint = Point(line);
        }

        if(line == "==="){
            furnitures.push_back(Furniture(startingPoint, furnitureMap));
            furnitureCounter++;

            furnitureMap.clear();
        } else{
            furnitureMap.push_back(line);
        }

        lineCounter++;

    }
}

void RoomModel::parsePaintBlocks() {
    int furnitureNumber = Point(rawRoomModel.furnitureAndPaintBlocksNumber).getX();

    int furnitureCounter = 0;
    int lineCounter = 0;

    while(furnitureCounter < furnitureNumber){
        std::string line = rawRoomModel.furnituresAndPaintBlocks[lineCounter];

        if(line == "==="){
            furnitureCounter++;

        }

        lineCounter++;
    }

    while (lineCounter < rawRoomModel.furnituresAndPaintBlocks.size()){
        std::string line = rawRoomModel.furnituresAndPaintBlocks[lineCounter];
        paintBlocks.push_back(Point(line));
    }
}
