//
// Created by TZ on 10/11/2023.
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H
#include <utility>
#include <string>

using namespace std;

int countBits(int number);
bool setBit(int& number, int order);
double mean(double *array, int size);
double stddev(double *array, int numElements);
pair<double, double> max2(double array[], int numElements);
int countWords(string text);
string code(string text);
string deCode(string text);
string capitalizeWords(string text);

//Extra
string removePunctuation(string &word);

#endif //CPP_2022_FUNCTIONS_H
