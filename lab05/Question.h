//
// Created by TZ on 10/23/2023.
//

#ifndef CPP_2022_QUESTION_H
#define CPP_2022_QUESTION_H

#include <string>
#include <vector>
#include "Answer.h"

using namespace std;

class Question {
private:
    string text;
    vector<Answer> answers;

public:
    Question() = default;

    void setText(const string &text) {
        this->text = text;
    }

    void setAnswers(const vector<Answer> &answers) {
        this->answers = answers;
    }

    const string &getText() const {
        return text;
    }

    const vector<Answer> &getAnswers() const {
        return answers;
    }
};

#endif //CPP_2022_QUESTION_H
