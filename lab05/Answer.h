//
// Created by TZ on 10/23/2023.
//

#ifndef CPP_2022_ANSWER_H
#define CPP_2022_ANSWER_H

#include <string>

using namespace std;

class Answer {
private:
    string text;
    bool correct;
public:
    Answer(string text = "", bool correct = false)
            : text(text), correct(correct) {
    }

    void setText(const string text) {
        this->text = text;
    }

    void setCorrect(bool correct) {
        this->correct = correct;
    }

    string getText() const {
        return text;
    }

    bool getCorrect() const {
        return correct;
    }
};

#endif //CPP_2022_ANSWER_H
