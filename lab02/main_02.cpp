#include <iostream>
#include "Point.h"
#include "Util.h"

using namespace std;

int main(int argc, char** argv) {
    Point p1(2,3);
    //cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    p1.print();
    cout<<endl;
    Point p2(100, 200);
    //cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    p2.print();
    cout<<endl;

    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    //cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    pp1->print();
    cout<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    cout<<endl;

    delete pp1;
    delete pp2;
    testIsSquare("points.txt");
    cout<<endl;

    int numPoints = 10;
    Point *points = createArray(numPoints);
    for (int i = 0; i < numPoints; i++) {
        points[i] = Point(rand() % 2000, rand() % 2000);
        //cout<<"p["<<i<<"]( "<<points[i].getX()<<","<<points[i].getY()<<")"<<endl;
    }
    printArray(points, numPoints);
    cout<<endl;

    pair<Point, Point> closestPair = closestPoints(points, numPoints);
    cout << "Legkozelebbi pontpar: " << endl;
    closestPair.first.print();
    closestPair.second.print();

    pair<Point, Point> farthestPair = farthestPoints(points, numPoints);
    cout << "Legtavolabbi pontpar: " << endl;
    farthestPair.first.print();
    farthestPair.second.print();
    cout<<endl;

    cout << "Rendezett pontok: " << endl;
    sortPoints(points, numPoints);
    printArray(points, numPoints);
    cout<<endl;

    Point* farthest = farthestPointsFromOrigin(points, numPoints);
    cout << "Az origotol legtavolabbi 10 pont:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "(" << farthest[i].getX() << ", " << farthest[i].getY() << ")" << endl;
    }


    deletePoints(points);
    return 0;
}
