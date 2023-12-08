//
// Created by TZ on 12/4/2023.
//

#include <fstream>
#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    int id;
    string fname, lname;
    while (ifs >> id >> fname >> lname) {
        students.emplace(id, Student(id, fname, lname));
    }
    ifs.close();
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    int id;
    double grade;
    while (ifs >> id >> grade) {
        try {
            students.at(id).addGrade(subject, grade);
        } catch (out_of_range &e) {
            cerr << "Student with id " << id << " does not exist!" << endl;
        }
    }
    ifs.close();
}

void GraduationDao::computeAverage() {
    for (auto &student: students) {
        student.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for (auto &student: students) {
        if (student.second.getGrade("Math") >= 5.0 && student.second.getGrade("Romanian") >= 5.0 &&
            student.second.getGrade("Hungarian") >= 5.0 && student.second.getAverage() >= 6.0) {
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    try{
        return students.at(id);
    }catch (out_of_range& e){
        cerr << "Student with id " << id << " does not exist!" << endl;
        exit(1);
    }
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0.0;
    for(auto& student : students){
        sum += student.second.getGrade(subject);
    }
    return sum / students.size();
}