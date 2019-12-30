//
// Created by jivko on 28.11.19.
//

#include "RoomModel.h"

RoomModel::RoomModel(RawRoomModel roomModel) : rawRoomModel(roomModel) {
    parseJerryPosition();
    parseTomPosition();
    parseFurnitures();
    parsePaintBlocks();

    createRoom();
}

void RoomModel::parseJerryPosition() {
    jerryPosition = Point(rawRoomModel.getJerryCoordinates());

}

void RoomModel::parseTomPosition() {
    tomPosition = Point(rawRoomModel.getTomCoordinates());
}

void RoomModel::parseFurnitures() {
    int furnitureNumber = Point(rawRoomModel.getFurnitureAndPaintBlocksNumber()).getX();

    int furnitureCounter = 0;
    int lineCounter = 0;
    Point startingPoint;
    std::vector<std::string> furnitureMap;
    while(furnitureCounter < furnitureNumber && lineCounter < rawRoomModel.getFurnituresAndPaintBlocks().size()){
        std::string line = rawRoomModel.getFurnituresAndPaintBlocks()[lineCounter];

        if(lineCounter == 0 || rawRoomModel.getFurnituresAndPaintBlocks()[lineCounter - 1] == "==="){

            startingPoint = Point(line);
        } else if(line == "==="){

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
    int furnitureNumber = Point(rawRoomModel.getFurnitureAndPaintBlocksNumber()).getX();

    int furnitureCounter = 0;
    int lineCounter = 0;

    while(furnitureCounter < furnitureNumber && lineCounter < rawRoomModel.getFurnituresAndPaintBlocks().size()){
        std::string line = rawRoomModel.getFurnituresAndPaintBlocks()[lineCounter];

        if(line == "==="){
            furnitureCounter++;

        }

        lineCounter++;
    }

    while (lineCounter < rawRoomModel.getFurnituresAndPaintBlocks().size()){
        std::string line = rawRoomModel.getFurnituresAndPaintBlocks()[lineCounter];
        paintBlocks.push_back(Point(line));
        lineCounter++;
    }
}

void RoomModel::createRoom() {
    Point roomSize(rawRoomModel.getRoomSize());

    std::string wall(roomSize.getX() + 2, '1');
    room.push_back(wall);

    std::string emptySpace(roomSize.getX(), ' ');
    for (int i = 0; i < roomSize.getY(); ++i) {
        room.push_back('1' + emptySpace + '1');
    }

    room.push_back(wall);

    for(Furniture furniture : furnitures){
        for (int i = 0; i < furniture.getFurnitureMap().size(); ++i) {
            std::string furniturePart = furniture.getFurnitureMap()[i];
            for (int j = 0; j < furniturePart.length(); ++j) {
                room[furniture.getStartingPoint().getY() + i + 1][furniture.getStartingPoint().getX() + j + 1] = furniturePart[j];
            }
        }
    }

    room[getTomPosition().getY() + WALLS_OFFSET][getTomPosition().getX() + WALLS_OFFSET] = 't';
    room[getJerryPosition().getY() + WALLS_OFFSET][getJerryPosition().getX() + WALLS_OFFSET] = 'j';
}

const Point &RoomModel::getJerryPosition() const {
    return jerryPosition;
}

const Point &RoomModel::getTomPosition() const {
    return tomPosition;
}

const std::vector<Point> &RoomModel::getPaintBlocks() const {
    return paintBlocks;
}

const std::vector<std::string> &RoomModel::getRoom() const {
    return room;
}
