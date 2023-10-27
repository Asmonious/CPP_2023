#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Point.h"
#include "PointSet.h"

using namespace std;


int main() {
//    vector<int> v;
//    v.reserve(16);
//
//    cout << "Size: " << v.size() << endl;
//    cout << "Capacity: " << v.capacity() << endl;
//    //Feltöltés: új elem hozzáadása: push_back VAGY emplace_back
//    for (int i = 0; i < 10; ++i) {
//        v.push_back(rand() % 100);
//    }
//    //Kiíratás
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//    cout << "Size: " << v.size() << endl;
//    cout << "Capacity: " << v.capacity() << endl;
//    cout << "-------------------------" << endl;
//    //Tömb kiíratása iterátorral
//    sort(v.begin(), v.end());
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//    cout << "-------------------------" << endl;
//    //Tömb kiíratása iterátorral csökkenő sorrendben
//    sort(v.begin(), v.end(), greater<int>());
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//
//    sort(v.begin(), v.end(), [](int a, int b) {
//        return a > b;
//    });
    Point p1;
    Point p2(2, 2);
    cout << p1.distanceTo(p2) << endl;

    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }
    return 0;
}