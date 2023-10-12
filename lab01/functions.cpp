//
// Created by TZ on 10/11/2023.
//
#include <cmath>
#include <sstream>
#include "functions.h"

int countBits(int number) {
    //implement this function
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int &number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }

    int mask = 1 << order;
    number |= mask;
    return true;
}

double mean(double *array, int size) {
    if (size == 0) {
        return NAN;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double) sum / size;
}

double stddev(double *array, int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double meanValue = mean(array, numElements);
    double sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += (array[i] - meanValue) * (array[i] - meanValue);
    }
    return sqrt(sum / numElements);
}

pair<double, double> max2(double *array, int numElements) {
    pair<double, double> result = {NAN, NAN};
    if (numElements <= 0) {
        return result;
    } else if (numElements == 1) {
        result.first = array[0];
        result.second = array[0];
        return result;
    }
    double firstMax = array[0];
    double secondMax = array[1];
    if (firstMax < secondMax) {
        swap(firstMax, secondMax);
    }
    for (int i = 2; i < numElements; ++i) {
        if (array[i] > firstMax) {
            secondMax = firstMax;
            firstMax = array[i];
        } else if (array[i] > secondMax) {
            secondMax = array[i];
        }
    }
    result.first = firstMax;
    result.second = secondMax;
    return result;
}

int countWords(string text) {
    istringstream iss(text);
    string word;
    int count = 0;
    while (iss >> word) {
        count++;
    }
    return count;

}

string code(string text) {
    for (char &c: text) {
        if (::isalpha(c)) {
            if (c == 'z' || c == 'Z') {
                c -= 25;
            } else {
                c++;
            }
        }

    }
    return text;
}

string deCode(string text) {
    for (char &c: text) {
        if (::isalpha(c)) {
            if (c == 'a' || c == 'A') {
                c += 25;
            } else {
                c--;
            }
        }
    }
    return text;
}

string capitalizeWords(string text) {
    bool capitalizeNext = true;
    for (char &c: text) {
        if (::isalpha(c)) {
            if (capitalizeNext) {
                c = toupper(c);
                capitalizeNext = false;
            } else {
                c = ::tolower(c);
            }
        }else {
                capitalizeNext = true;
            }
        }
    return text;
}

string removePunctuation(string &word) {
    string result;
    for(char &c: word) {
        if(::isalnum(c) || c == '\''){
            result += c;
        }
    }
    return result;
}



