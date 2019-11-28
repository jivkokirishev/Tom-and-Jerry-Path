//
// Created by jivko on 13.11.19.
//

#ifndef TOM_AND_JERRY_PATH_FILEEXTRACTOR_H
#define TOM_AND_JERRY_PATH_FILEEXTRACTOR_H


#include <string>
#include <vector>
#include <fstream>
#include <queue>

class FileExtractor {
public:
    FileExtractor(std::string fileName);

    std::queue<std::string> extractRawFile();

private:
    std::string fileName;
};


#endif //TOM_AND_JERRY_PATH_FILEEXTRACTOR_H
