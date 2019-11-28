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
