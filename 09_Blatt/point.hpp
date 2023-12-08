#pragma once
#include <vector>

struct Point
{
    int x,y;

    // necessary for unique
    bool operator==(const Point& otherPoint) const {
        return x == otherPoint.x && y == otherPoint.y;
    }
    bool operator<(const Point& otherPoint) const {
        if (y < otherPoint.y) {
            return true;
        }
        if (y == otherPoint.y && x < otherPoint.x) {
            return true;
        }
        return false;
    }
};

using PointContainer = std::vector<Point>;
