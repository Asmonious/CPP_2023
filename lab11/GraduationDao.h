//
// Created by TZ on 12/4/2023.
//

#ifndef CPP_2022_GRADUATIONDAO_H
#define CPP_2022_GRADUATIONDAO_H

#include "Student.h"
#include <iostream>

using namespace std;

class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {} //explicit azt jelenti hogy mikor letrehozzuk csak igy lehet
    // -> GraduationDao dao1(1990) egy ertekesel csak
    void enrollStudents(const string &filename);
    void saveGradesForSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
// throws out_of_range exception for nonexistent id
    Student findById(int id) const;
    double getAverageBySubject(const string &subject) const;
};


#endif //CPP_2022_GRADUATIONDAO_H
