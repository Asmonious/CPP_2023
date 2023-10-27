//
// Created by TZ on 10/26/2023.
//

#ifndef CPP_2022_UTIL_H
#define CPP_2022_UTIL_H

#include "Point.h"

double distance(const Point &a, const Point &b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
bool compareX(const Point &a, const Point &b);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
void deletePoints(Point* points);
void sortPoints(Point* points, int numPoints);
void printArray(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);



#endif //CPP_2022_UTIL_H
