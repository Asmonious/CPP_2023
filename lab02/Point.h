//
// Created by TZ on 10/26/2023.
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H

using namespace std;

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
    double distance(const Point& a, const Point& b);

};



#endif //CPP_2022_POINT_H
