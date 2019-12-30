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
    Point(int x, int y);

private:
    int x;
public:
    int getX() const;

    int getY() const;

    bool operator==(const Point& other) const;

private:
    int y;

};


#endif //TOM_AND_JERRY_PATH_POINT_H
