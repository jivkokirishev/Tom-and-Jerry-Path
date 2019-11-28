//
// Created by jivko on 13.11.19.
//

#include "FileExtractor.h"

FileExtractor::FileExtractor(std::string fileName) : fileName(fileName){

}

std::queue<std::string> FileExtractor::extractRawFile() {
    std::queue<std::string> rawFileLines;

    std::ifstream file;
    file.open(fileName);
    std::string line;
    if (file.is_open()){
        while (std::getline(file, line)) {
            rawFileLines.push(line);
        }
    }
}
