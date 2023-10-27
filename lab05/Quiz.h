//
// Created by TZ on 10/23/2023.
//

#ifndef CPP_2022_QUIZ_H
#define CPP_2022_QUIZ_H
#include <string>
#include <stdexcept>
#include "Question.h"


using namespace std;


class Quiz {
private:
    string name;
    vector<Question> questions;
    void readQuestion(const string &filename);
public:
    Quiz(const string &name, const string &filename){
        this->name = name;
        readQuestion(filename);
    }
    string getName() const {
        return name;
    }
    vector<Question> getQuestions() const {
        return questions;
    }
    int getNumQuestions() const {
        return questions.size();
    }
    const Question &getQuestion(int index) const {
        if(index < 0 || index >= questions.size())
            throw out_of_range("Invalid index");
        return questions[index];
    }

};


#endif //CPP_2022_QUIZ_H
