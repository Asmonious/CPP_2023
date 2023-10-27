#include <iostream>
#include "Quiz.h"
#include "QuizGame.h"

using namespace std;

int main() {
    Quiz quiz("ITQuiz", "quiz1.txt");
    cout << "Quiz name: " << quiz.getName() << endl;
    cout << "Number of questions: " << quiz.getNumQuestions() << endl;
    cout << "Pick the correct answer!" << endl << endl;
    QuizGame quizGame1(quiz, 0);
    quizGame1.playGame();
    return 0;
}