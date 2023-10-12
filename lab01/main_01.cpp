#include <iostream>
#include <sstream>
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]) {
    //1. test code for the countBits function
    cout << "Test code for the countBits function" << endl;
    int n = 7;
    cout << "The number of bits in " << n << " is " << countBits(n) << endl;
    n = 8;
    cout << "The number of bits in " << n << " is " << countBits(n) << endl;
//    for (int i = 0; i <= 127; ++i) {
//        cout << "The number of bits in " << i << " is " << countBits(i) << endl;
//
//    }

    cout << "2." << endl;
    //2.
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if (setBit(n, i)) {
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }

    cout << "3." << endl;
    //3.
    cout << "Test code for the mean function" << endl;
    double array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "The mean of the array is " << mean(array, size) << endl;
    double emptyArray[] = {};
    size = sizeof(emptyArray) / sizeof(emptyArray[0]);
    cout << "The mean of the empty array is " << mean(emptyArray, size) << endl;

    cout << "4." << endl;
    //4.
    cout << "Test code for the stdev function" << endl;
    double array2[] = {3.5, 8, 15, 2.7, 6};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    cout << "The standard deviation of the array is " << stddev(array2, size2) << endl;

    cout << "5." << endl;
    //5.
    cout << "Test code for the max2 function" << endl;
    cout << "The max of the array is " << max2(array2, size2).first << " and the second max is "
         << max2(array2, size2).second << endl;

    cout << endl;
    cout << "Karakterlancok" << endl;
    cout << "1. Feladat:" << endl;
    //1.
    double sum = 0.0;
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        istringstream iss(arg);
        double num;

        if (iss >> num) {
            sum += num;
        }
    }
    cout << "Az osszeg: " << sum << endl;

    cout << "2. Feladat:" << endl;
    //2.
    string text = "Na hany szo van ebben a mondatban?";
    cout << "A szavak szama: " << countWords(text) << endl;

    cout << "3. Feladat:" << endl;
    //3.
    cout << "Eredeti szoveg: " << text << endl;
    cout << "Kodolva: " << code(text) << endl;
    cout << "Decodolva: " << deCode(code(text)) << endl;

    cout << "4. Feladat:" << endl;
    //4.
    string line;
    while (getline(cin, line)) {
        cout << capitalizeWords(line) << endl;
    }
    return 0;
}
