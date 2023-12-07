#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    Student stud1(1, "Nagy", "Kalman");
    stud1.addGrade("Math", 9);
    stud1.addGrade("Romanian", 7);
    stud1.addGrade("Hungarian", 10);
    stud1.computeAverage();
    cout << stud1 << endl;
    //cout << stud1.getGrade("Romanian");
    return 0;
}