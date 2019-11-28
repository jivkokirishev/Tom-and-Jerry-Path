//
// Created by jivko on 14.11.19.
//

#ifndef TOM_AND_JERRY_PATH_POINT_H
#define TOM_AND_JERRY_PATH_POINT_H


#include <string>

class Point {
public:
    Point();
    Point(std::string coordinates);

    int getX();
    int getY();

private:
    int x;
    int y;

};


#endif //TOM_AND_JERRY_PATH_POINT_H
