//
// Created by jivko on 13.11.19.
//

#include "StreamParser.h"

StreamParser::StreamParser(std::string fileName) : fileName(fileName){

    this->processStream();
}

void StreamParser::processStream() {
    std::ifstream file;
    file.open(fileName);
    std::string line;
    if (file.is_open()) {
        int lineCounter = 0;
        while (std::getline(file, line)) {

            int furnitureDescrCounter = 0;
            int paintBlocksCounter = 0;

            switch (lineCounter){
                case 0:{
                    roomSize = coordinatesParser(line);
                }break;
                case 1:{
                    jerryPosition = coordinatesParser(line);
                }break;
                case 2:{
                    tomPosition = coordinatesParser(line);
                }break;
                case 3:{
                    int* furnitureAndPaintNumbers = coordinatesParser(line);

                    furnitureDescrCounter = furnitureAndPaintNumbers[0];
                    paintBlocksCounter = furnitureAndPaintNumbers[1];

                    delete[] furnitureAndPaintNumbers;

                    if(furnitureDescrCounter > 0){
                        this->furniture.push_back(std::vector<std::string>());
                    }
                }break;
            }

            if(lineCounter >= 4){
                while (furnitureDescrCounter != 0){
                    if(line == "==="){
                        furnitureDescrCounter--;

                        if(furnitureDescrCounter != 0){
                            this->furniture.push_back(std::vector<std::string>());
                        }
                    } else{
                        this->furniture.back().push_back(line);
                    }
                }

                if(furnitureDescrCounter == 0){
                    while (paintBlocksCounter != 0){
                        int* pair = coordinatesParser(line);
                        paintPermissionedBlocks.push_back(pair);
                        paintBlocksCounter--;
                    }
                }
            }

            lineCounter++;
        }
    }
    file.close();
}

int *StreamParser::coordinatesParser(std::string coordinates) {
    int *pair = new int[2];

    std::string delimiter = " ";
    std::string width = coordinates.substr(0, coordinates.find(delimiter));
    std::string length = coordinates.substr(coordinates.find(delimiter) + 1, coordinates.length());

    pair[0] = std::stoi(width);
    pair[1] = std::stoi(length);

    return pair;
}

int *StreamParser::getRoomSize() {
    return roomSize;
}

int *StreamParser::getTomPosition() {
    return tomPosition;
}

int *StreamParser::getJerryPosition() {
    return jerryPosition;
}

std::vector<std::vector<std::string>> StreamParser::getFurniture() {
    return furniture;
}

std::vector<int *> StreamParser::getPaintPermissionedBlocks() {
    return paintPermissionedBlocks;
}
