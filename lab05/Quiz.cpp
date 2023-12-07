//
// Created by TZ on 10/23/2023.
//

#include "Quiz.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale>
#include <codecvt>

using namespace std;

string removeAccents(const string &str) {
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring wstr = conv.from_bytes(str);

    wstring noAccents = L"";
    for (wchar_t c: wstr) {
        if (iswalpha(c)) {
            if (c == L'á') {
                noAccents += L'a';
            } else if (c == L'é') {
                noAccents += L'e';
            } else if (c == L'í') {
                noAccents += L'i';
            } else if (c == L'ó' || c == L'ö' || c == L'ő') {
                noAccents += L'o';
            } else if (c == L'ü' || c == L'ű' || c == L'ú') {
                noAccents += L'u';
            } else if (c == L'Á') {
                noAccents += L'A';
            } else if (c == L'É') {
                noAccents += L'E';
            } else if (c == L'Í') {
                noAccents += L'I';
            } else if (c == L'Ó' || c == L'Ö' || c == L'Ő') {
                noAccents += L'O';
            } else if (c == L'Ü' || c == L'Ű' || c == L'Ú') {
                noAccents += L'U';
            } else {
                noAccents += c;
            }
        } else {
            noAccents += c;
        }
    }

    return conv.to_bytes(noAccents);
}

void Quiz::readQuestion(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }
    string line;
    Question question;
    vector<Answer> answers;
    while (getline(file, line)) {
        switch (line[0]) {
            case 'Q':
                question.setText(removeAccents(line.substr(2)));
                answers.clear();
                break;
            case 'A':
                answers.emplace_back(removeAccents(line.substr(2)));
                break;
            default:
                istringstream iss(line);
                int val;
                while (iss >> val) {
                    answers[val - 1].setCorrect(true);
                }
                question.setAnswers(answers);
                questions.push_back(question);
                break;
        }
    }
}


