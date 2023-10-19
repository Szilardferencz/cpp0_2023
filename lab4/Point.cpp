//
// Created by Szilárd on 10/19/2023.
//

#include "Point.h"
#include <cmath>

Point::Point(int x, int y) : x(x), y(y) {
    if (x < 0) this->x = 0;
    if (x > M) this->x = M;
    if (y < 0) this->y = 0;
    if (y > M) this->y = M;
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

double Point::distanceTo(const Point& point) const {
    int dx = x - point.x;
    int dy = y - point.y;
    return sqrt(static_cast<double>(dx * dx + dy * dy));
}

