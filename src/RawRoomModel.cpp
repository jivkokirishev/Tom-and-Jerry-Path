//
// Created by jivko on 28.11.19.
//

#include "RawRoomModel.h"

RawRoomModel::RawRoomModel(std::queue<std::string> fileLines) {
    roomSize = fileLines.front();
    fileLines.pop();

    jerryCoordinates = fileLines.front();
    fileLines.pop();

    tomCoordinates = fileLines.front();
    fileLines.pop();

    furnitureAndPaintBlocksNumber = fileLines.front();
    fileLines.pop();

    while (!fileLines.empty()){
        furnituresAndPaintBlocks.push_back(fileLines.front());
        fileLines.pop();
    }

}

const std::string &RawRoomModel::getRoomSize() const {
    return roomSize;
}

const std::string &RawRoomModel::getJerryCoordinates() const {
    return jerryCoordinates;
}

const std::string &RawRoomModel::getTomCoordinates() const {
    return tomCoordinates;
}

const std::string &RawRoomModel::getFurnitureAndPaintBlocksNumber() const {
    return furnitureAndPaintBlocksNumber;
}

const std::vector<std::string> &RawRoomModel::getFurnituresAndPaintBlocks() const {
    return furnituresAndPaintBlocks;
}
