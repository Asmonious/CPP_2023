#include <iostream>
#include "Quiz.h"
#include "QuizGame.h"

using namespace std;

int main() {
//    Quiz quiz("ITQuiz", "quiz1.txt");
//    cout << "Quiz name: " << quiz.getName() << endl;
//    cout << "Number of questions: " << quiz.getNumQuestions() << endl;
//    cout << "Pick the correct answer!" << endl << endl;
//    QuizGame quizGame1(quiz, 0);
//    quizGame1.playGame();
//    return 0;
    User users[] = {User("Peter"), User("Kati")};
    Quiz quizzes[] = {Quiz("cpp1"), Quiz("cpp2")};
    int num_users = sizeof(users) / sizeof(users[0]);
    int num_quizzes = sizeof(quizzes) / sizeof(quizzes[0]);
    for (int i = 0; i < num_users; ++i) {
        for (int j = 0; j < num_quizzes; ++j) {
            QuizGame game(users[i], quizzes[j]);
            game.playGame();
            cout << "Name: " << game.getUser().getName() << ", score: " <<
                 game.getScore() << endl << endl;
        }
    }
    cout << endl << "****************" << endl;
    cout << "Users' results:" << endl;
    for (int i = 0; i < num_users; ++i) {
        cout << users[i] << endl;
    }
    cout << "****************" << endl;
    return 0;


}