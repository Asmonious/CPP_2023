//
// Created by TZ on 10/26/2023.
//

#include <complex>
#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return this->x;
}
int Point::getY() const {
    return this->y;
}

void Point::print() const {
    cout << "(" << this->x << "," << this->y << ")" << endl;
}


