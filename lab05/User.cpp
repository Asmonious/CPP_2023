//
// Created by TZ on 11/6/2023.
//

#include "User.h"

User::User(const string &name) {
    this->id = counter++;
    this->name = name;


}

int User::getId() const {
    return id;
}

const string &User::getName() const {
    return name;
}

void User::addScore(const string &quizName, double score) {
    scores[quizName] = score;

}

double User::getScore(const string &quizName) const {
    return scores.at(quizName);
}

void User::print(ostream &os) const {
    os << "User: " << name << endl;
    os << "Scores: " << endl;
    for(auto it = scores.begin(); it != scores.end(); it++){
        os << it->first << ": " << it->second << endl;
    }
}

ostream &operator<<(ostream &os, const User &user) {
    user.print(os);
    return os;
}
