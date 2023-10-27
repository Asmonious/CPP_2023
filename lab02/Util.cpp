//
// Created by TZ on 10/26/2023.
//

#include <cmath>
#include "util.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double ab = distance(a, b);
    double ac = distance(a, c);
    double ad = distance(a, d);
    double bc = distance(b, c);
    double bd = distance(b, d);
    double cd = distance(c, d);
    if (ab == ac && ac == ad && ad == bc && bc == bd && bd == cd) {
        return true;
    }
    return false;
}

void testIsSquare(const char *filename) {
    ifstream file(filename);
    if (!file) {
        //sikertelen megnyitas error message
        cerr << "Unable to open file " << filename << endl;
        return;
    }
    while (true) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (file.eof()) {
            break;
        }
        Point p1(x1, y1);
        Point p2(x2, y2);
        Point p3(x3, y3);
        Point p4(x4, y4);
        p1.print();
        cout << " ";
        p2.print();
        cout << " ";
        p3.print();
        cout << " ";
        p4.print();
        cout << " : ";
        if (isSquare(p1, p2, p3, p4)) {
            cout << "square" << endl;
        } else {
            cout << "not a square" << endl;
        }
    }
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    return points;
}


pair<Point, Point> closestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        cerr << "Nincs elég pont a párosításhoz." << endl;
        return std::make_pair(Point(0, 0), Point(0, 0));
    }

    sort(points, points + numPoints, compareX);
    double minDistance = distance(points[0], points[1]);
    pair<Point, Point> closestPair(points[0], points[1]);

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double currentDistance = distance(points[i], points[j]);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return closestPair;
}


void deletePoints(Point *points) {
    if (points != nullptr) {
        delete[] points;
    }

}

bool compareX(const Point &a, const Point &b) {
    return a.getX() < b.getX();
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, compareX);
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
        cout << " ";
    }
    cout << endl;

}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        cerr << "Nincs elég pont a párosításhoz." << endl;
        return std::make_pair(Point(0, 0), Point(0, 0));
    }

    double maxDistance = distance(points[0], points[1]);
    pair<Point, Point> farthestPair(points[0], points[1]);

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double currentDistance = distance(points[i], points[j]);
            if (currentDistance > maxDistance) {
                maxDistance = currentDistance;
                farthestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return farthestPair;
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    if (numPoints < 2) {
        cerr << "Nincs elég pont a párosításhoz." << endl;
        return nullptr;
    }

    Point *farthestPoints = new Point[10];
    double farthestDistances[10] = {0};

    for (int i = 0; i < numPoints; ++i) {
        double currentDistance = distance(Point(0, 0), points[i]);


        for (int j = 0; j < 10; ++j) {
            if (currentDistance > farthestDistances[j]) {

                for (int k = 9; k > j; --k) {
                    farthestDistances[k] = farthestDistances[k - 1];
                    farthestPoints[k] = farthestPoints[k - 1];
                }
                farthestDistances[j] = currentDistance;
                farthestPoints[j] = points[i];
                break;
            }
        }
    }

    return farthestPoints;
}

