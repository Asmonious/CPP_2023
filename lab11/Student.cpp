//
// Created by TZ on 12/4/2023.
//

#include <iomanip>
#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName): id(id), firstName(firstName), lastName(lastName)  {

}

int Student::getId() const {
    return this->id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return this->firstName;
}

const string &Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {
    if(subject == "Math" || subject == "Romanian" || subject == "Hungarian"){
        this->grades[subject] = grade;
    } else {
        throw out_of_range("Subject nonexistent!");
    }
}

double Student::getGrade(const string &subject) const {
    return this->grades.at(subject);
}

const map<string, double> &Student::getGrades() const {
    return this->grades;
}

void Student::computeAverage() {
    double sum = 0.0;
    for(auto& grade :  this->grades){
        sum += grade.second;
    }
    this->average = sum / this->grades.size();
}

double Student::getAverage() const {
    return this->average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "Student: " << student.firstName << " " << student.lastName << endl;
    os << " \tID: " << student.id << " \n\tGrades: ";
    for(auto& grade : student.grades){
        os << grade.first << " - " << grade.second << "; ";
    }
    os << "\n\tAverage: " << fixed << setprecision(2) << student.average << endl;
}

