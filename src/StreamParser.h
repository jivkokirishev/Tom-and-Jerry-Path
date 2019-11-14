//
// Created by jivko on 13.11.19.
//

#ifndef TOM_AND_JERRY_PATH_STREAMPARSER_H
#define TOM_AND_JERRY_PATH_STREAMPARSER_H


#include <string>
#include <vector>
#include <fstream>

class StreamParser {
public:
    StreamParser(std::string fileName);

    int* getRoomSize();
    int* getTomPosition();
    int* getJerryPosition();
    std::vector<std::vector<std::string>>  getFurniture();
    std::vector<int*> getPaintPermissionedBlocks();
    //std::vector<char> getCommands();

private:
    std::string fileName;

    int* roomSize;
    int* tomPosition;
    int* jerryPosition;
    std::vector<std::vector<std::string>> furniture;
    std::vector<int*> paintPermissionedBlocks;
    //std::vector<char> commands;

    void processStream();

    void setRoomSize();
    void setTomPosition();
    void setJerryPosition();
    void setFurniture();
    //void setCommands();

    int* coordinatesParser(std::string coordinates);


};


#endif //TOM_AND_JERRY_PATH_STREAMPARSER_H
