//
// Created by TZ on 10/28/2023.
//

#ifndef CPP_2022_QUIZGAME_H
#define CPP_2022_QUIZGAME_H


#include "Quiz.h"

class QuizGame {
private:
    Quiz quiz;
    int playerScore;
public:
    QuizGame(const Quiz &quiz, int start) : quiz(quiz), playerScore(0) {}

    void playGame();
};


#endif //CPP_2022_QUIZGAME_H
