//
// Created by TZ on 10/16/2023.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"

PointSet::PointSet(int n) {
    this->n = n;
    this->points.reserve(n);
    this->distances.reserve(n * (n - 1) / 2);

    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range


    while (points.size() < n) {
        int x = dist(mt);
        int y = dist(mt);
        //csak kulonbozo pontok! addig generalunk, amig nem lesz n darab kulonbozo pont

        points.push_back(Point(x, y));
    }
    computeDistances();

}

void PointSet::computeDistances() {
    for(int i= 0; i< points.size();i++){
        for(int j = i+1; j< points.size();j++){
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }

}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for(int i = 0; i< points.size();i++){
        cout<<points[i].getX()<<" "<<points[i].getY()<<endl;
    }

}

void PointSet::printDistances() const {
    for(int i = 0; i< distances.size();i++){
        cout<<distances[i]<<endl;
    }

}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](Point a, Point b){
        return a.getX()<b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](Point a, Point b){
        return a.getY()<b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    sortDistances();
    int count = 1;
    for(int i = 1; i< distances.size();i++){
        if(distances[i]!=distances[i-1]){
            count++;
        }
    }
    return count;
}
