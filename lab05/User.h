//
// Created by TZ on 11/6/2023.
//

#ifndef CPP_2022_USER_H
#define CPP_2022_USER_H

#include <iostream>
#include <map>


using namespace std;

class User {
private:
    int id;
    string name;
    map<string, double> scores;
    int counter;
public:
    User(const string& name);
    int getId() const;
    const string& getName() const;
    void addScore(const string& quizName, double score);
    double getScore(const string& quizName) const;
    void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const User& user);
};

#endif //CPP_2022_USER_H
