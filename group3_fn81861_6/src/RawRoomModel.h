//
// Created by jivko on 28.11.19.
//

#ifndef TOM_AND_JERRY_PATH_RAWROOMMODEL_H
#define TOM_AND_JERRY_PATH_RAWROOMMODEL_H

#include <string>
#include <queue>
#include <vector>


class RawRoomModel {
public:
    RawRoomModel(std::queue<std::string> fileLines);

private:
    std::string roomSize;
public:
    const std::string &getRoomSize() const;

    const std::string &getJerryCoordinates() const;

    const std::string &getTomCoordinates() const;

    const std::string &getFurnitureAndPaintBlocksNumber() const;

    const std::vector<std::string> &getFurnituresAndPaintBlocks() const;

private:
    std::string jerryCoordinates;
    std::string tomCoordinates;
    std::string furnitureAndPaintBlocksNumber;
    std::vector<std::string> furnituresAndPaintBlocks;

};


#endif //TOM_AND_JERRY_PATH_RAWROOMMODEL_H
