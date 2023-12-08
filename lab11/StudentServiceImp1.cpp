//
// Created by TZ on 12/9/2023.
//

#include "StudentServiceImp1.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    try{
        dao->findById(id);
        return true;
    }catch (out_of_range& e){
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    try{
        auto grades = dao->findById(id).getGrades();
        vector<string> subjects;
        for(auto& grade : grades){
            subjects.push_back(grade.first);
        }
        return subjects;
    }catch (out_of_range& e){
        throw out_of_range("Student with id " + to_string(id) + " does not exist!");
    }
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    try{
        return dao->findById(id).getGrade(subject);
    }catch (out_of_range& e){
        throw out_of_range("Student with id " + to_string(id) + " does not exist!");
    }
}

double StudentServiceImpl::getAverage(int id) const {
    try{
        return dao->findById(id).getAverage();
    }catch (out_of_range& e){
        throw out_of_range("Student with id " + to_string(id) + " does not exist!");
    }
}

bool StudentServiceImpl::isPassed(int id) const {
    try{
        if(dao->findById(id).getGrade("Math") >= 5.0 && dao->findById(id).getGrade("Romanian") >= 5.0 &&
                dao->findById(id).getGrade("Hungarian") >= 5.0 && dao->findById(id).getAverage() >= 6.0){
            return true;
        }
        return false;
    }catch (out_of_range& e){
        throw out_of_range("Student with id " + to_string(id) + " does not exist!");
    }
}




