//
// Created by TZ on 10/28/2023.
//

#include "QuizGame.h"
#include <iostream>

void QuizGame::playGame() {
    for (int i = 0; i < quiz.getNumQuestions(); ++i) {
        cout << "Question " << i + 1 << ": " << quiz.getQuestion(i).getText() << endl;

        for (int j = 0; j < quiz.getQuestion(i).getAnswers().size(); ++j) {
            cout << j + 1 << ". " << quiz.getQuestion(i).getAnswers()[j].getText() << endl;
        }

        int userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer < 1 || userAnswer > quiz.getQuestion(i).getAnswers().size()) {
            cout << "Invalid answer. Try again in the range 1-" << quiz.getQuestion(i).getAnswers().size() << "\n" << endl;
            --i;
            continue;
        } else {
            if (quiz.getQuestion(i).getAnswers()[userAnswer - 1].getCorrect()) {
                cout << "This is correct!\n" << endl;
                playerScore++;
            } else {
                cout << "Incorrect!" <<endl <<" The correct answer is: ";
                for (int j = 0; j < quiz.getQuestion(i).getAnswers().size(); ++j) {
                    if (quiz.getQuestion(i).getAnswers()[j].getCorrect()) {
                        cout << j + 1 << ". " << quiz.getQuestion(i).getAnswers()[j].getText() << "  ";
                    }
                }
                cout << "\n" << endl;
            }
        }
    }

    cout << "Quiz completed. YOUR SCORE: " << playerScore << "/" << quiz.getNumQuestions() << endl;
}