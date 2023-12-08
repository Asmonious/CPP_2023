//
// Created by TZ on 12/9/2023.
//

#ifndef CPP_2022_STUDENTSERVICEIMP1_H
#define CPP_2022_STUDENTSERVICEIMP1_H


#include "GraduationDao.h"
#include "StudentService.h"

using namespace std;

class StudentServiceImpl : public StudentService{
    GraduationDao *dao;
public:
    StudentServiceImpl(GraduationDao *dao) : dao(dao) {}
    virtual bool isEnrolled(int id) const override;
    vector<string> getSubjects(int id) const override;
    double getResultBySubject(int id, const string& subject) const override;
    double getAverage(int id) const override;
    bool isPassed(int id) const override;
};


#endif //CPP_2022_STUDENTSERVICEIMP1_H
