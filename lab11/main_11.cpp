#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImp1.h"

using namespace std;

int main() {
//    Student stud1(1, "Nagy", "Kalman");
//    stud1.addGrade("Math", 9);
//    stud1.addGrade("Romanian", 7);
//    stud1.addGrade("Hungarian", 10);
//    stud1.computeAverage();
//    cout << stud1 << endl;
    //cout << stud1.getGrade("Romanian");

    GraduationDao dao(2023);
    //Az én filejaim nagy betűvel kezdődnek!!!
    string subjects[] = {"Math", "Romanian", "Hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout << "Number of passed students: " << dao.numPassed() << endl;
    cout << "Average grade for Math: " << dao.getAverageBySubject("Math") << endl;
    cout << "Average grade for Romanian: " << dao.getAverageBySubject("Romanian") << endl;
    cout << "Average grade for Hungarian: " << dao.getAverageBySubject("Hungarian") << endl;

    //3. Exercise

    StudentService *service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector <string> subjects = service->getSubjects(id);
        for (int i = 0; i < subjects.size(); ++i) {
            cout << "\t" << subjects[i] << ": " <<
                 service->getResultBySubject(id, subjects[i]) << endl;
        }
        cout << "\tAverage: " << service->getAverage(id) << endl;
    }
    delete service;


    return 0;
}