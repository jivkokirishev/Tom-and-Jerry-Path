//
// Created by jivko on 28.11.19.
//

#ifndef TOM_AND_JERRY_PATH_ROOMMODEL_H
#define TOM_AND_JERRY_PATH_ROOMMODEL_H


#include "RawRoomModel.h"
#include "Point.h"
#include "Furniture.h"

class RoomModel {
public:
    RoomModel(RawRoomModel roomModel);

private:
    RawRoomModel rawRoomModel;

    Point jerryPosition;
public:
    const Point &getJerryPosition() const;

    const Point &getTomPosition() const;

    const std::vector<Point> &getPaintBlocks() const;

    const std::vector<std::string> &getRoom() const;

private:
    Point tomPosition;
    std::vector<Furniture> furnitures;
    std::vector<Point> paintBlocks;
    std::vector<std::string> room;

    void parseJerryPosition();
    void parseTomPosition();
    void parseFurnitures();
    void parsePaintBlocks();
    void createRoom();
};


#endif //TOM_AND_JERRY_PATH_ROOMMODEL_H
